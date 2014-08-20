#ifndef PAYINFO_H
#define PAYINFO_H
struct alipay_info{
#if 0
    char *imsi;
    char *order_key;
    char *order_time;
    char *order_subject;
    char *total_fee;
    int  order_number;
#endif
    char imsi[16+1];
    char order_key[32+1];
    char order_time[19+1];
    char order_subject[128+1];
    char total_fee[15+1];
    int  order_number;
};
#endif
