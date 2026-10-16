#include "zf_common_headfile.h"
#include "flash_app.h"
#include "menu.h"
// ================= 配置保存位置 =================
// 警告：请务必确保这两个宏定义的值不会覆盖你当前的程序代码！
// 通常使用最后一个扇区（如63）和最后一个页（如3）比较安全
#define MENU_SAVE_SECTOR    63
#define MENU_SAVE_PAGE      3


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     将 menu 相关的三个变量保存到 Flash 中
// 使用示例     在检测到按键按下的代码逻辑中调用 menu_data_save();
//-------------------------------------------------------------------------------------------------------------------
void menu_data_save(void)
{
    // 逐飞库 API 要求传入 uint32 类型的指针数组
    // 因为 int 在 CH32V307（RISC-V 32位架构）上正好是 4 字节（32位），所以可以直接强转存储
    uint32 save_buffer[3];
    
    // 1. 打包数据（注意顺序，读取时要对应）
    save_buffer[0] = (uint32)menu_level;
    save_buffer[1] = (uint32)menu_level1_n;
    save_buffer[2] = (uint32)menu_level2_n;
    
    // 2. 写入 Flash
    // 参数说明：扇区号, 页号, 数据指针, 数据长度(以4字节/1个字为单位)
    // 此函数内部会自动检查该页是否有数据，如果有会先擦除整个扇区再写入
    uint8 result = flash_write_page(MENU_SAVE_SECTOR, MENU_SAVE_PAGE, save_buffer, 3);
    
    if(result == 0)
    {
        // 写入成功
        tft180_show_string(0,32,"save success");
    }
    else
    {
        // 写入失败 
        tft180_show_string(0,32,"save failed");
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     上电时从 Flash 中读取 menu 相关的三个变量
// 使用示例     在 main 函数初始化时，或者 menu 初始化函数中调用 menu_data_load();
//-------------------------------------------------------------------------------------------------------------------
void menu_data_load(void)
{
    // 1. 先检查该扇区该页是否存过数据 (0-没有数据, 1-有数据)
    // 如果没存过，说明是首次上电，不应该去读，否则会读出乱码 0xE339E339
    if(flash_check(MENU_SAVE_SECTOR, MENU_SAVE_PAGE))
    {
        uint32 read_buffer[3];
        
        // 2. 读取数据
        flash_read_page(MENU_SAVE_SECTOR, MENU_SAVE_PAGE, read_buffer, 3);
        
        // 3. 解包赋值（注意与保存时的顺序一致）
        menu_level    = (int)read_buffer[0];
        menu_level1_n = (int)read_buffer[1];
        menu_level2_n = (int)read_buffer[2];
        tft180_show_string(0,32,"Menu data loaded");
        // printf("Menu data loaded successfully!\r\n");
    }
    else
    {
        // 首次上电没有历史数据，可以在此处赋默认值
        menu_level    = 0;
        menu_level1_n = 0;
        menu_level2_n = 0;
        tft180_show_string(0,32,"No Menu data");
        // printf("No menu data found, set to default.\r\n");
    }
}