#pragma once

/* Littlevgl specific */
#include "lvgl.h"
#include "lvgl_helpers.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_system.h"
#include "driver/gpio.h"

#include "main.h"

#ifdef __cplusplus
extern "C"
{
#endif

    void lv_tick_task(void *arg);
    void create_application(void);

#ifdef __cplusplus
}
#endif