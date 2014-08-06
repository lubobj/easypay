#ifndef ALIQR_H 
#define ALIQR_H 
/* pay information struct (must) */
struct payInfo {
    char imsi[16+1];
    char order_key[32+1];
    int  order_number;
    char order_time[19+1];
    char order_subject[128+1];
    char total_fee[15+1];
}; 
//int alipay_precreate(char* precr, int* len, struct payInfo* order_info);
#endif
