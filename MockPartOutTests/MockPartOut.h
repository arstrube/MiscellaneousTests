#ifndef _MOCKPARTOUT_

typedef struct Mpo {
    float f;
	unsigned char other_stuff_ar[3];
	unsigned char my_ar[4];
	long l;
} Mpo_t;

void Mpo_init(void);

void Mpo_doit(void);

Mpo_t* Mpo_get(void);

/// Stub example function; defined in some other module

void Otr_func(Mpo_t* p);

#endif // _MOCKPARTOUT_
