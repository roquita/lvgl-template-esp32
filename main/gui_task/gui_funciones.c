#include "gui_funciones.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "GUI_FUNCIONES"

static void led_event_cb(struct _lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_PRESSED)
    {
        lv_led_toggle(obj);
    }
}

static void monochrome_app()
{
    /* use a pretty small demo for monochrome displays */
    /* Get the current screen  */
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);

    /*Create a Label on the currently active screen*/
    lv_obj_t *label1 = lv_label_create(scr, NULL);

    /*Modify the Label's text*/
    lv_label_set_text(label1, "Hello\nworld");

    /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
}
static void multichrome_app()
{
    //lv_demo_widgets();
    lv_obj_t *led = lv_led_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(led, led_event_cb);
    lv_obj_set_width(led, 100);
    lv_obj_set_height(led, 100);
    lv_obj_set_pos(led, 10, 30);

    /*
    lv_obj_t *container = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_auto_realign(container, true);
    lv_cont_set_fit(container, LV_FIT_TIGHT);
    lv_cont_set_layout(container, LV_LAYOUT_COLUMN_MID);
*/

    //lv_obj_t *checkbox = lv_checkbox_create(lv_scr_act(), NULL);
    //lv_checkbox_set_text(checkbox, "CLICK ME");

    lv_obj_t *suich = lv_switch_create(lv_scr_act(), NULL);
    lv_obj_set_pos(suich, 130, 30);
    lv_obj_set_size(suich, 100, 50);
}

void create_application(void)
{
    /* When using a monochrome display we only show "Hello World" centered on the 
     * screen */
#if defined CONFIG_LV_TFT_DISPLAY_MONOCHROME || \
    defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S

    monochrome_app();

#else
    /* Otherwise we show the selected demo */
    multichrome_app();

#endif
}

void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}
