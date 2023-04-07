#include "sdb.h"
#define nr_instexec 65536

struct reg_record
{
    const char *inst_name;
    word_t reg_value;
};
// A reg_history struct will record a register's value in each execution of NEMU
// register_records so tht
struct reg_history
{
    int nr_exec;
    struct reg_record single_register_record[nr_instexec];
} register_records[32];

void init_reglog()
{
    // TODO, this will cause NEMU assert just after compile finish
    for(int i = 0; i < 32; i = i + 1)
    {
        register_records[i].nr_exec = 0;
        for(int j = 0; j < nr_instexec ; j = j + 1)
        {
            register_records[i].single_register_record -> inst_name = NULL;
            register_records[i].single_register_record -> reg_value = 0;
        }
    }
    Log("reglog initialized!");
    return;
}

void reglog_print(int register_number)
{
    // TODO
    assert(0);
    return;
}

void reglog_print_all()
{
    // TODO
    assert(0);
    return;
}

void reglog_record(word_t register_values[], word_t pc)
{
    // TODO
    assert(0);
    return;
}