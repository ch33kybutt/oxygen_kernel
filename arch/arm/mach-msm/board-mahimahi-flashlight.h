#ifndef __ASM_ARM_ARCH_FLASHLIGHT_H
#define __ASM_ARM_ARCH_FLASHLIGHT_H
#include <linux/earlysuspend.h>

#define FLASHLIGHT_NAME "flashlight"

#define FLASHLIGHT_OFF   0
#define FLASHLIGHT_TORCH 1
#define FLASHLIGHT_FLASH 2
#define FLASHLIGHT_NUM   3

enum flashlight_mode_flags {
	FL_MODE_OFF = 0,
	FL_MODE_TORCH,
	FL_MODE_FLASH,
	FL_MODE_PRE_FLASH,
	FL_MODE_TORCH_LED_A,
	FL_MODE_TORCH_LED_B,
	FL_MODE_TORCH_LEVEL_1,
	FL_MODE_TORCH_LEVEL_2,
	FL_MODE_DEATH_RAY,
};

struct flashlight_platform_data {
	void (*gpio_init) (void);
	uint32_t torch;
	uint32_t flash;
	uint32_t flash_adj;
	uint32_t flash_duration_ms;
	uint8_t led_count; /* 0: 1 LED, 1: 2 LED */
};

int flashlight_control(int mode);
int aat1271_flashlight_control(int mode);
int adp1650_flashlight_control(int mode);

#undef __ASM_ARM_ARCH_FLASHLIGHT_H
#endif
