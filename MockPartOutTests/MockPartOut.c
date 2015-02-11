#include "MockPartOut.h"

static Mpo_t inaccessible_st;

void Mpo_init(void)
{
	int i, start = 1;
	inaccessible_st.f = 17.95;
    for (i=0; i<3; i++) inaccessible_st.other_stuff_ar[i]=start++;
    inaccessible_st.l = 999999;
    for (i=0; i<4; i++) inaccessible_st.my_ar[i]=start++;
    for (i=0; i<2; i++) inaccessible_st.more_stuff_ar[i]=start++;
}

Mpo_t* Mpo_get(void)
{
    return &inaccessible_st;
}

void Mpo_doit(void)
{
	test_mock_func(&inaccessible_st);
}
