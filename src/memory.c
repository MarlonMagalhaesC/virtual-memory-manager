#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "config.h"
#include "page_table.h"
#include "tlb.h"

static signed char physical_memory[NUM_FRAMES][FRAME_SIZE];

static int frame_to_page[NUM_FRAMES];

static FILE *backing = NULL;

void memory_init(FILE *backing_store)
{
    backing = backing_store;

    for (int i = 0; i < NUM_FRAMES; i++)
    {
        frame_to_page[i] = -1;

        for (int j = 0; j < FRAME_SIZE; j++)
        {
            physical_memory[i][j] = 0;
        }
    }
}

static int find_free_frame(void)
{
    for (int i = 0; i < NUM_FRAMES; i++)
    {
        if (frame_to_page[i] == -1)
        {
            return i;
        }
    }

    return -1;
}

int handle_page_fault(int page)
{

    if (page < 0 || page >= PAGE_TABLE_SIZE)
    {
        fprintf(stderr, "Erro: pagina invalida.\n");
        exit(1);
    }

    int frame = find_free_frame();

    if (frame == -1)
    {
        int victim_page = select_victim_page();
        if (victim_page == -1)

        {
            fprintf(stderr, "Erro: nenhuma pagina vitima encontrada.\n");
            exit(1);
        }

        frame = page_table_get_frame(victim_page);

        if (frame < 0 || frame >= NUM_FRAMES)
        {
            fprintf(stderr, "Erro: frame invalido\n");
            exit(1);
        }

        page_table_invalidate(victim_page);

        tlb_remove(victim_page);
    }

    if (backing == NULL)
    {
        fprintf(stderr,
                "Erro interno: BACKING_STORE nao inicializado.\n");
        exit(1);
    }

    if (fseek(backing, page * PAGE_SIZE, SEEK_SET) != 0)
    {
        fprintf(stderr, "Erro: falha ao posicionar BACKING_STORE na pagina %d.\n", page);
        exit(1);
    }

    size_t bytes_read = fread(physical_memory[frame], sizeof(signed char), PAGE_SIZE, backing);

    if (bytes_read != PAGE_SIZE)
    {
        fprintf(stderr, "Erro: falha ao ler pagina %d do BACKING_STORE.\n", page);
        exit(1);
    }

    frame_to_page[frame] = page;

    page_table_update(page, frame);

    return frame;
}

int select_victim_page(void)
{
    int victim = -1;
    unsigned char menor = 255;

    for (int i = 0; i < PAGE_TABLE_SIZE; i++)
    {
        if (page_table_is_valid(i))
        {
            unsigned char counter = page_table_get_aging_counter(i);

            if (victim == -1)
            {
                victim = i;
                menor = counter;
            }
            else if (counter < menor)
            {
                victim = i;
                menor = counter;
            }
        }
    }
    return victim;
}

signed char read_memory(int frame, int offset)
{
    if (frame < 0 || frame >= NUM_FRAMES)
    {
        return 0;
    }

    if (offset < 0 || offset >= FRAME_SIZE)
    {
        return 0;
    }

    return physical_memory[frame][offset];
}

int get_page_loaded_in_frame(int frame)
{
    if (frame < 0 || frame >= NUM_FRAMES)
    {
        return -1;
    }

    return frame_to_page[frame];
}
