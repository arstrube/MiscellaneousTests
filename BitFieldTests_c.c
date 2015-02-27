#include "BitFieldTests_c.h"

boolean Bf_IsFieldSet(uint8 field_u8)
{
    Data_t* data_pst;
    data_pst = Bf_GetData();

    if (NULL_PTR != data_pst) {
        switch (field_u8) {
            case 1:
                if(FALSE != (sint16)data_pst->field1_u16) return TRUE;
                else return FALSE;
            case 2:
                if(FALSE != (sint16)data_pst->field2_u16) return TRUE;
                else return FALSE;
            case 3:
                if(FALSE != (sint16)data_pst->field3_u16) return TRUE;
                else return FALSE;
            case 4:
                if(FALSE != (sint16)data_pst->field4_u16) return TRUE;
                else return FALSE;
        }
    }
    
    return FALSE;
}
