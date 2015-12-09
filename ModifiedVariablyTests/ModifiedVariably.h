#ifndef MODIFIEDVARIABLY_H
#define MODIFIEDVARIABLY_H

#define RESULT_MAX 96u
#define ALIGN_BYTES_TO_4 4u
#define ALIGN_BYTES_TO_8 8u
#define ALIGN_BYTES_TO_64 64u

#define X_MAX 0.0f
#define X_MIN -80.0f
#define X_RES 5.0f
#define MAX_INDEX_X (unsigned short)((X_MAX - X_MIN) / (X_RES) )
#define X_CELL 32u
#define MAX_X (MAX_INDEX_X * X_CELL)
#define MODIFIED_VARIABLY_4  (MAX_X % ALIGN_BYTES_TO_4)
#define MODIFIED_VARIABLY_8  (MAX_X % ALIGN_BYTES_TO_8)
#define MODIFIED_VARIABLY_64  (MAX_X % ALIGN_BYTES_TO_64)

/** NOTE: It looks like the reserved[] array is not needed and wasteful. 
          This would be necessary if we wanted to align to odd boundaries,
          which seems somewhat unlikely to me.
*/

typedef struct Test_align_4_st {
   unsigned char indices[ RESULT_MAX ];
   unsigned char reserved[ ALIGN_BYTES_TO_4 - MODIFIED_VARIABLY_4];
} Test_align_4_st;

typedef struct Test_align_8_st {
   unsigned char indices[ RESULT_MAX ];
   unsigned char reserved[ ALIGN_BYTES_TO_8 - MODIFIED_VARIABLY_8];
} Test_align_8_st;

typedef struct Test_align_64_st {
   unsigned char indices[ RESULT_MAX ];
   unsigned char reserved[ ALIGN_BYTES_TO_64 - MODIFIED_VARIABLY_64];
} Test_align_64_st;

typedef struct Test_align_4c_st {
   unsigned char indices[ RESULT_MAX ] __attribute__ ((aligned (ALIGN_BYTES_TO_4))) ;;
} Test_align_4c_st;

typedef struct Test_align_8c_st {
   unsigned char indices[ RESULT_MAX ] __attribute__ ((aligned (ALIGN_BYTES_TO_8))) ;;
} Test_align_8c_st;

typedef struct Test_align_64c_st {
   unsigned char indices[ RESULT_MAX ]  __attribute__ ((aligned (ALIGN_BYTES_TO_64))); ;
} Test_align_64c_st;

#endif