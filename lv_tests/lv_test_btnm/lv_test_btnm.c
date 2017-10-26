/**
 * @file lv_test_btnm.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>  /*For printf in the action*/

#include "lv_test_btnm.h"

#if USE_LV_BTNM != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_action_res_t btnm_action(lv_obj_t * btnm, const char * txt);

/**********************
 *  STATIC VARIABLES
 **********************/
#if TXT_UTF8 != 0
static const char * btnm_map[] = {"One line", "\n", "\212", "\204üŰöŐ", "\221éÉ","\n", "\214", "\202Left", ""};
#else
static const char * btnm_map[] = {"One line", "\n", "\212", "\204long", "\221short","\n", "\214", "\202Left", ""};
#endif
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a default object and test the basic functions
 */
void lv_test_btnm_1(void)
{
    /* Default object
     * GOAL: A button matrix with default buttons */
    lv_obj_t * btnm1 = lv_btnm_create(lv_scr_act(), NULL);

    /* Test map, size and position. Also try some features.
     * GOAL: A button matrix with default buttons.  */
    static lv_style_t rel;
    lv_style_copy(&rel, lv_style_get(LV_STYLE_BUTTON_ON_RELEASED));
    rel.body.color_main = COLOR_RED;
    rel.body.color_gradient = COLOR_BLACK;
    rel.text.color = COLOR_YELLOW;

    static lv_style_t pr;
    lv_style_copy(&pr, lv_style_get(LV_STYLE_BUTTON_ON_RELEASED));
    pr.body.color_main = COLOR_ORANGE;
    pr.body.color_gradient = COLOR_BLACK;
    pr.text.color = COLOR_WHITE;


    lv_obj_t * btnm2 = lv_btnm_create(lv_scr_act(), NULL);
    lv_btnm_set_map(btnm2, btnm_map);
    lv_obj_set_size_scale(btnm2, 200, 100);
    lv_obj_align(btnm2, btnm1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_btnm_set_toggle(btnm2, true, 2);
    lv_btnm_set_action(btnm2, btnm_action);
    lv_btnm_set_button_style(btnm2, LV_BTN_STATE_OFF_RELEASED, &rel);
    lv_btnm_set_button_style(btnm2, LV_BTN_STATE_OFF_PRESSED, &pr);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static lv_action_res_t btnm_action(lv_obj_t * btnm, const char * txt)
{
    /* On PC */
     printf("%s\n", txt);

    return LV_ACTION_RES_OK;
}

#endif /*USE_LV_BTNM*/
