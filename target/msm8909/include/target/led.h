#ifndef _TARGET_MSM8909_LED_H
#define _TARGET_MSM8909_LED_H
struct lv5216_reg {
    uint8_t reg;
    uint8_t val;
};
extern struct lv5216_reg lv5216_init_regs[];

extern struct lv5216_reg lv5216_backlight_on[];
extern struct lv5216_reg lv5216_backlight_off[];

int lv5216_send(struct lv5216_reg *buf, int count);
int lv5216_init(void);

#endif
