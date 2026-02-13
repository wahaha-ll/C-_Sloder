/**
 * @file bootSkin_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bootSkin_gen.h"
#include "E_Desktop_C_Sloder.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_loading_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * bootSkin_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "bootSkin_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_t * boot_skin_img = lv_image_create(lv_obj_0);
    lv_obj_set_name(boot_skin_img, "boot_skin_img");
    lv_image_set_src(boot_skin_img, bootSkinImg);
    
    lv_obj_add_screen_create_event(lv_obj_0, LV_EVENT_ALL, mainScreen_create, LV_SCREEN_LOAD_ANIM_OUT_BOTTOM, 100, 2280);
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _BOOTSKIN_TIMELINE_CNT);
    at_array[BOOTSKIN_TIMELINE_LOADING] = timeline_loading_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, bootSkin_get_timeline(lv_obj_0, BOOTSKIN_TIMELINE_LOADING), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * bootSkin_get_timeline(lv_obj_t * obj, bootSkin_timeline_t timeline_id)
{
    if (timeline_id >= _BOOTSKIN_TIMELINE_CNT) {
        LV_LOG_WARN("bootSkin has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_loading_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "boot_skin_img"));
    lv_anim_set_values(&a, -240, 60);
    lv_anim_set_duration(&a, 240);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "boot_skin_img"));
    lv_anim_set_values(&a, 60, -30);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 240, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "boot_skin_img"));
    lv_anim_set_values(&a, -30, 15);
    lv_anim_set_duration(&a, 160);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 440, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "boot_skin_img"));
    lv_anim_set_values(&a, 15, 0);
    lv_anim_set_duration(&a, 140);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 600, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _BOOTSKIN_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

