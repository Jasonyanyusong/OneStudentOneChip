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
    for(int i = 0; i < 32; i = i + 1)
    {
        register_records[i].nr_exec = 0;
        for(int j = 0; j < nr_instexec ; j = j + 1)
        {
            register_records[i].single_register_record[j].inst_name = NULL;
            register_records[i].single_register_record[j].reg_value = 0;
        }
    }
    Log("reglog initialized!");
    return;
}

void reglog_print(int register_number)
{
    IFNDEF(CONFIG_REGLOG, return);
    printf("Reglog print register No.%d, this register have %d execution histories.\n", register_number, register_records[register_number].nr_exec);
    for(int i = 0; i < register_records[register_number].nr_exec; i = i + 1)
    {
        printf("Exec #%d, Inst \"%s\", Reg (Hex) 0x%8lx, Reg (Dec) 0d%10ld, Reg (Bin) 0b%s", i, register_records[register_number].single_register_record[i].inst_name, register_records[register_number].single_register_record[i].reg_value, register_records[register_number].single_register_record[i].reg_value, register_records[register_number].single_register_record[i].inst_name);
    }
    return;
}

void reglog_print_all()
{
    IFNDEF(CONFIG_REGLOG, return);
    for(int i = 0; i < 32; i = i + 1)
    {
        reglog_print(i);
    }
    return;
}

void reglog_record(word_t register_values[], word_t pc)
{
    IFNDEF(CONFIG_REGLOG, return);
    // TODO
    assert(0);
    return;
}