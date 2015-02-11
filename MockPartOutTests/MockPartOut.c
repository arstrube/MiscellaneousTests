#include "MockPartOut.h"

static Mpo_t inaccessible_st;

void Mpo_init(void)
{
	int i, start = 1;
	inaccessible_st.f = 17.95;
    for (i=0; i<3; i++) inaccessible_st.other_stuff[i]=start++;
    for (i=0; i<4; i++) inaccessible_st.to_modify[i]=start++;
    inaccessible_st.l = 999999;
}

Mpo_t* Mpo_get(void)
{
    return &inaccessible_st;
}

void Mpo_doit(void)
{
	Otr_func(&inaccessible_st);
}
