idf_component_register(
    SRCS "main.cpp" "gui_task/gui_task.c" "gui_task/gui_funciones.c"
    INCLUDE_DIRS "." "gui_task"
    REQUIRES lvgl_esp32_drivers 
             lvgl 
             lvgl_tft 
             lvgl_touch 
             spi_flash
)

#target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")