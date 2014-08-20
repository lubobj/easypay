#ifndef PAYINFO_H
#define PAYINFO_H
struct alipay_info{
    char imsi[16+1];
    char order_key[32+1];
    char order_time[19+1];
    char order_subject[128+1];
    char total_fee[15+1];
    int  order_number;
};
#endif
