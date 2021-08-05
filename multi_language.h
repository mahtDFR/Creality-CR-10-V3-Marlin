#ifndef MULTI_LANGUAGE_H
#define MULTI_LANGUAGE_H

static unsigned char currentfontnameindex = 0;		// 0:en, 1:cn
static unsigned char tall_font_correction = 0;

#define FONT_EEPROM_OFFSET 99
static void set_select_font_index0_to_eeprom ()
{
	eeprom_write_byte((unsigned char*)FONT_EEPROM_OFFSET, (unsigned char)0);
}
static void set_select_font_index1_to_eeprom ()
{
	eeprom_write_byte((unsigned char*)FONT_EEPROM_OFFSET, (unsigned char)1);
}

static void(* reboot) (void) = 0;

static void lcd_select_lang()
{
	currentfontnameindex = eeprom_read_byte((unsigned char*)FONT_EEPROM_OFFSET);
	if (currentfontnameindex == 1)
	{
		tall_font_correction = 1;
	}
}

static void set_fontname(char font_nr)
{
	#if ENABLED(USE_BIG_EDIT_FONT)
		if (font_nr == FONT_MENU_EDIT)
		{
			u8g.setFont(FONT_MENU_EDIT_NAME);
		}
		else
		{
			switch (currentfontnameindex)
			{
				case 0:
					u8g.setFont(FONT_MENU_NAME_EN);
					break;
				case 1:
					u8g.setFont(FONT_MENU_NAME_CN);
					break;
				default:
					u8g.setFont(FONT_MENU_NAME_EN);
        			break;
			}
		}
	#else
		switch (currentfontnameindex)
		{
			case 0:
				u8g.setFont(FONT_MENU_NAME_EN);
				break;
			case 1:
				u8g.setFont(FONT_MENU_NAME_CN);
				break;
			default:
				u8g.setFont(FONT_MENU_NAME_EN);
				break;
		}
	#endif
}

/* MSG_BACK */
static const char* msg_back()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BACK);
		case 1:
			return PSTR(CN_MSG_BACK);
	}
	return PSTR(MSG_BACK);
}

/* MSG_SD_INSERTED */
static const char* msg_sd_inserted()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SD_INSERTED);
		case 1:
			return PSTR(CN_MSG_SD_INSERTED);
	}
	return PSTR(MSG_SD_INSERTED);
}

/* MSG_SD_REMOVED */
static const char* msg_sd_removed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SD_REMOVED);
		case 1:
			return PSTR(CN_MSG_SD_REMOVED);
	}
	return PSTR(MSG_SD_REMOVED);
}

/* MSG_MAIN */
static const char* msg_main()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MAIN);
		case 1:
			return PSTR(CN_MSG_MAIN);
	}
	return PSTR(MSG_MAIN);
}

/* MSG_AUTOSTART */
static const char* msg_autostart()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTOSTART);
		case 1:
			return PSTR(CN_MSG_AUTOSTART);
	}
	return PSTR(MSG_AUTOSTART);
}

/* MSG_DISABLE_STEPPERS */
static const char* msg_disable_steppers()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DISABLE_STEPPERS);
		case 1:
			return PSTR(CN_MSG_DISABLE_STEPPERS);
	}
	return PSTR(MSG_DISABLE_STEPPERS);
}

/* MSG_DEBUG_MENU */
static const char* msg_debug_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DEBUG_MENU);
		case 1:
			return PSTR(CN_MSG_DEBUG_MENU);
	}
	return PSTR(MSG_DEBUG_MENU);
}

/* MSG_PROGRESS_BAR_TEST */
static const char* msg_progress_bar_test()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PROGRESS_BAR_TEST);
		case 1:
			return PSTR(CN_MSG_PROGRESS_BAR_TEST);
	}
	return PSTR(MSG_PROGRESS_BAR_TEST);
}

/* MSG_AUTO_HOME */
static const char* msg_auto_home()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTO_HOME);
		case 1:
			return PSTR(CN_MSG_AUTO_HOME);
	}
	return PSTR(MSG_AUTO_HOME);
}

/* MSG_AUTO_HOME_X */
static const char* msg_auto_home_x()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTO_HOME_X);
		case 1:
			return PSTR(CN_MSG_AUTO_HOME_X);
	}
	return PSTR(MSG_AUTO_HOME_X);
}

/* MSG_AUTO_HOME_Y */
static const char* msg_auto_home_y()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTO_HOME_Y);
		case 1:
			return PSTR(CN_MSG_AUTO_HOME_Y);
	}
	return PSTR(MSG_AUTO_HOME_Y);
}

/* MSG_AUTO_HOME_Z */
static const char* msg_auto_home_z()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTO_HOME_Z);
		case 1:
			return PSTR(CN_MSG_AUTO_HOME_Z);
	}
	return PSTR(MSG_AUTO_HOME_Z);
}

/* MSG_LEVEL_BED_HOMING */
static const char* msg_level_bed_homing()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_BED_HOMING);
		case 1:
			return PSTR(CN_MSG_LEVEL_BED_HOMING);
	}
	return PSTR(MSG_LEVEL_BED_HOMING);
}

/* MSG_LEVEL_BED_WAITING */
static const char* msg_level_bed_waiting()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_BED_WAITING);
		case 1:
			return PSTR(CN_MSG_LEVEL_BED_WAITING);
	}
	return PSTR(MSG_LEVEL_BED_WAITING);
}

/* MSG_LEVEL_BED_NEXT_POINT */
static const char* msg_level_bed_next_point()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_BED_NEXT_POINT);
		case 1:
			return PSTR(CN_MSG_LEVEL_BED_NEXT_POINT);
	}
	return PSTR(MSG_LEVEL_BED_NEXT_POINT);
}

/* MSG_LEVEL_BED_DONE */
static const char* msg_level_bed_done()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_BED_DONE);
		case 1:
			return PSTR(CN_MSG_LEVEL_BED_DONE);
	}
	return PSTR(MSG_LEVEL_BED_WAITING);
}

/* MSG_Z_FADE_HEIGHT */
static const char* msg_z_fade_height()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_Z_FADE_HEIGHT);
		case 1:
			return PSTR(CN_MSG_Z_FADE_HEIGHT);
	}
	return PSTR(MSG_Z_FADE_HEIGHT);
}

/* MSG_SET_HOME_OFFSETS */
static const char* msg_set_home_offsets()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SET_HOME_OFFSETS);
		case 1:
			return PSTR(CN_MSG_SET_HOME_OFFSETS);
	}
	return PSTR(MSG_SET_HOME_OFFSETS);
}

/* MSG_HOME_OFFSETS_APPLIED */
static const char* msg_home_offsets_applied()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_HOME_OFFSETS_APPLIED);
		case 1:
			return PSTR(CN_MSG_HOME_OFFSETS_APPLIED);
	}
	return PSTR(MSG_HOME_OFFSETS_APPLIED);
}

/* MSG_SET_ORIGIN */
static const char* msg_set_origin()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SET_ORIGIN);
		case 1:
			return PSTR(CN_MSG_SET_ORIGIN);
	}
	return PSTR(MSG_SET_ORIGIN);
}

/* MSG_PREHEAT_1 */
static const char* msg_preheat_1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1);
	}
	return PSTR(MSG_PREHEAT_1);
}

/* MSG_PREHEAT_1_N1 */
static const char* msg_preheat_1_n1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_N MSG_H1);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_N MSG_H1);
	}
	return PSTR(MSG_PREHEAT_1_N MSG_H1);
}

/* MSG_PREHEAT_1_N2 */
static const char* msg_preheat_1_n2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_N MSG_H2);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_N MSG_H2);
	}
	return PSTR(MSG_PREHEAT_1_N MSG_H2);
}

/* MSG_PREHEAT_1_N3 */
static const char* msg_preheat_1_n3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_N MSG_H3);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_N MSG_H3);
	}
	return PSTR(MSG_PREHEAT_1_N MSG_H3);
}

/* MSG_PREHEAT_1_N4 */
static const char* msg_preheat_1_n4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_N MSG_H4);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_N MSG_H4);
	}
	return PSTR(MSG_PREHEAT_1_N MSG_H4);
}

/* MSG_PREHEAT_1_N5 */
static const char* msg_preheat_1_n5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_N MSG_H5);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_N MSG_H5);
	}
	return PSTR(MSG_PREHEAT_1_N MSG_H5);
}

/* MSG_PREHEAT_1_ALL */
static const char* msg_preheat_1_all()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_ALL);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_ALL);
	}
	return PSTR(MSG_PREHEAT_1_ALL);
}

/* MSG_PREHEAT_1_END */
static const char* msg_preheat_1_end()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END);
	}
	return PSTR(MSG_PREHEAT_1_END);
}

/* MSG_PREHEAT_1_END1 */
static const char* msg_preheat_1_end1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END " " MSG_E1);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END " " MSG_E1);
	}
	return PSTR(MSG_PREHEAT_1_END " " MSG_E1);
}

/* MSG_PREHEAT_1_END2 */
static const char* msg_preheat_1_end2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END " " MSG_E2);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END " " MSG_E2);
	}
	return PSTR(MSG_PREHEAT_1_END " " MSG_E2);
}

/* MSG_PREHEAT_1_END3 */
static const char* msg_preheat_1_end3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END " " MSG_E3);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END " " MSG_E3);
	}
	return PSTR(MSG_PREHEAT_1_END " " MSG_E3);
}

/* MSG_PREHEAT_1_END4 */
static const char* msg_preheat_1_end4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END " " MSG_E4);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END " " MSG_E4);
	}
	return PSTR(MSG_PREHEAT_1_END " " MSG_E4);
}

/* MSG_PREHEAT_1_END5 */
static const char* msg_preheat_1_end5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_END " " MSG_E5);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_END " " MSG_E5);
	}
	return PSTR(MSG_PREHEAT_1_END " " MSG_E5);
}

/* MSG_PREHEAT_1_BEDONLY */
static const char* msg_preheat_1_bedonly()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_BEDONLY);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_BEDONLY);
	}
	return PSTR(MSG_PREHEAT_1_BEDONLY);
}

/* MSG_PREHEAT_1_SETTINGS */
static const char* msg_preheat_1_setting()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_1_SETTINGS);
		case 1:
			return PSTR(CN_MSG_PREHEAT_1_SETTINGS);
	}
	return PSTR(MSG_PREHEAT_1_SETTINGS);
}

/* MSG_PREHEAT_2 */
static const char* msg_preheat_2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2);
	}
	return PSTR(MSG_PREHEAT_2);
}

/* MSG_PREHEAT_2_N1 */
static const char* msg_preheat_2_n1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_N MSG_H1);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_N MSG_H1);
	}
	return PSTR(MSG_PREHEAT_2_N MSG_H1);
}

/* MSG_PREHEAT_2_N2 */
static const char* msg_preheat_2_n2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_N MSG_H2);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_N MSG_H2);
	}
	return PSTR(MSG_PREHEAT_2_N MSG_H2);
}

/* MSG_PREHEAT_2_N3 */
static const char* msg_preheat_2_n3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_N MSG_H3);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_N MSG_H3);
	}
	return PSTR(MSG_PREHEAT_2_N MSG_H3);
}

/* MSG_PREHEAT_2_N4 */
static const char* msg_preheat_2_n4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_N MSG_H4);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_N MSG_H4);
	}
	return PSTR(MSG_PREHEAT_2_N MSG_H4);
}

/* MSG_PREHEAT_2_N5 */
static const char* msg_preheat_2_n5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_N MSG_H5);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_N MSG_H5);
	}
	return PSTR(MSG_PREHEAT_2_N MSG_H5);
}

/* MSG_PREHEAT_2_ALL */
static const char* msg_preheat_2_all()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_ALL);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_ALL);
	}
	return PSTR(MSG_PREHEAT_2_ALL);
}

/* MSG_PREHEAT_2_END */
static const char* msg_preheat_2_end()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END);
	}
	return PSTR(MSG_PREHEAT_2_END);
}

/* MSG_PREHEAT_2_END1 */
static const char* msg_preheat_2_end1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END " " MSG_E1);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END " " MSG_E1);
	}
	return PSTR(MSG_PREHEAT_2_END " " MSG_E1);
}

/* MSG_PREHEAT_2_END2 */
static const char* msg_preheat_2_end2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END " " MSG_E2);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END " " MSG_E2);
	}
	return PSTR(MSG_PREHEAT_2_END " " MSG_E2);
}

/* MSG_PREHEAT_2_END3 */
static const char* msg_preheat_2_end3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END " " MSG_E3);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END " " MSG_E3);
	}
	return PSTR(MSG_PREHEAT_2_END " " MSG_E3);
}

/* MSG_PREHEAT_2_END4 */
static const char* msg_preheat_2_end4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END " " MSG_E4);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END " " MSG_E4);
	}
	return PSTR(MSG_PREHEAT_2_END " " MSG_E4);
}

/* MSG_PREHEAT_2_END5 */
static const char* msg_preheat_2_end5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_END " " MSG_E5);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_END " " MSG_E5);
	}
	return PSTR(MSG_PREHEAT_2_END " " MSG_E5);
}

/* MSG_PREHEAT_2_BEDONLY */
static const char* msg_preheat_2_bedonly()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_BEDONLY);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_BEDONLY);
	}
	return PSTR(MSG_PREHEAT_2_BEDONLY);
}

/* MSG_PREHEAT_2_SETTINGS */
static const char* msg_preheat_2_settings()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREHEAT_2_SETTINGS);
		case 1:
			return PSTR(CN_MSG_PREHEAT_2_SETTINGS);
	}
	return PSTR(MSG_PREHEAT_2_SETTINGS);
}

/* MSG_COOLDOWN */
static const char* msg_cooldown()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_COOLDOWN);
		case 1:
			return PSTR(CN_MSG_COOLDOWN);
	}
	return PSTR(MSG_COOLDOWN);
}

/* MSG_SWITCH_PS_ON */
static const char* msg_switch_ps_on()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SWITCH_PS_ON);
		case 1:
			return PSTR(CN_MSG_SWITCH_PS_ON);
	}
	return PSTR(MSG_SWITCH_PS_ON);
}

/* MSG_SWITCH_PS_OFF */
static const char* msg_switch_ps_off()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SWITCH_PS_OFF);
		case 1:
			return PSTR(CN_MSG_SWITCH_PS_OFF);
	}
	return PSTR(MSG_SWITCH_PS_OFF);
}

/* MSG_EXTRUDE */
static const char* msg_extrude()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_EXTRUDE);
		case 1:
			return PSTR(CN_MSG_EXTRUDE);
	}
	return PSTR(MSG_EXTRUDE);
}

/* MSG_RETRACT */
static const char* msg_retract()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_RETRACT);
		case 1:
			return PSTR(CN_MSG_RETRACT);
	}
	return PSTR(MSG_RETRACT);
}

/* MSG_MOVE_AXIS */
static const char* msg_move_axis()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_AXIS);
		case 1:
			return PSTR(CN_MSG_MOVE_AXIS);
	}
	return PSTR(MSG_MOVE_AXIS);
}

/* MSG_BED_LEVELING */
static const char* msg_bed_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BED_LEVELING);
		case 1:
			return PSTR(CN_MSG_BED_LEVELING);
	}
	return PSTR(MSG_BED_LEVELING);
}

/* MSG_LEVEL_BED */
static const char* msg_level_bed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_BED);
		case 1:
			return PSTR(CN_MSG_LEVEL_BED);
	}
	return PSTR(MSG_LEVEL_BED);
}

/* MSG_LEVEL_CORNERS */
static const char* msg_level_corners()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LEVEL_CORNERS);
		case 1:
			return PSTR(CN_MSG_LEVEL_CORNERS);
	}
	return PSTR(MSG_LEVEL_CORNERS);
}

/* MSG_NEXT_CORNER */
static const char* msg_next_corner()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NEXT_CORNER);
		case 1:
			return PSTR(CN_MSG_NEXT_CORNER);
	}
	return PSTR(MSG_NEXT_CORNER);
}

/* MSG_USER_MENU */
static const char* msg_user_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_USER_MENU);
		case 1:
			return PSTR(CN_MSG_USER_MENU);
	}
	return PSTR(MSG_USER_MENU);
}

/* MSG_UBL_TOOLS */
static const char* msg_ubl_tools()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_TOOLS);
		case 1:
			return PSTR(CN_MSG_UBL_TOOLS);
	}
	return PSTR(MSG_UBL_TOOLS);
}

/* MSG_UBL_LEVEL_BED */
static const char* msg_ubl_level_bed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_LEVEL_BED);
		case 1:
			return PSTR(CN_MSG_UBL_LEVEL_BED);
	}
	return PSTR(MSG_UBL_LEVEL_BED);
}

/* MSG_UBL_MANUAL_MESH */
static const char* msg_ubl_manual_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MANUAL_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_MANUAL_MESH);
	}
	return PSTR(MSG_UBL_MANUAL_MESH);
}

/* MSG_UBL_ACTIVATE_MESH */
static const char* msg_ubl_activate_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_ACTIVATE_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_ACTIVATE_MESH);
	}
	return PSTR(MSG_UBL_ACTIVATE_MESH);
}

/* MSG_UBL_DEACTIVATE_MESH */
static const char* msg_ubl_deactivate_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_DEACTIVATE_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_DEACTIVATE_MESH);
	}
	return PSTR(MSG_UBL_DEACTIVATE_MESH);
}

/* MSG_UBL_CUSTOM_BED_TEMP */
static const char* msg_ubl_custom_bed_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_CUSTOM_BED_TEMP);
		case 1:
			return PSTR(CN_MSG_UBL_CUSTOM_BED_TEMP);
	}
	return PSTR(MSG_UBL_CUSTOM_BED_TEMP);
}

/* MSG_UBL_SET_HOTEND_TEMP */
static const char* msg_ubl_set_hotend_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_SET_HOTEND_TEMP);
		case 1:
			return PSTR(CN_MSG_UBL_SET_HOTEND_TEMP);
	}
	return PSTR(MSG_UBL_SET_HOTEND_TEMP);
}

/* MSG_UBL_CUSTOM_HOTEND_TEMP */
static const char* msg_ubl_custom_hotend_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_CUSTOM_HOTEND_TEMP);
		case 1:
			return PSTR(CN_MSG_UBL_CUSTOM_HOTEND_TEMP);
	}
	return PSTR(MSG_UBL_CUSTOM_HOTEND_TEMP);
}

/* MSG_UBL_MESH_EDIT */
static const char* msg_ubl_mesh_edit()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MESH_EDIT);
		case 1:
			return PSTR(CN_MSG_UBL_MESH_EDIT);
	}
	return PSTR(MSG_UBL_MESH_EDIT);
}

/* MSG_UBL_BUILD_CUSTOM_MESH */
static const char* msg_ubl_build_custom_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_BUILD_CUSTOM_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_BUILD_CUSTOM_MESH);
	}
	return PSTR(MSG_UBL_BUILD_CUSTOM_MESH);
}

/* MSG_UBL_BUILD_MESH_MENU */
static const char* msg_ubl_build_mesh_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_BUILD_MESH_MENU);
		case 1:
			return PSTR(CN_MSG_UBL_BUILD_MESH_MENU);
	}
	return PSTR(MSG_UBL_BUILD_MESH_MENU);
}

/* MSG_UBL_BUILD_PLA_MESH */
static const char* msg_ubl_build_pla_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_BUILD_PLA_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_BUILD_PLA_MESH);
	}
	return PSTR(MSG_UBL_BUILD_PLA_MESH);
}

/* MSG_UBL_BUILD_ABS_MESH */
static const char* msg_ubl_build_abs_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_BUILD_ABS_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_BUILD_ABS_MESH);
	}
	return PSTR(MSG_UBL_BUILD_ABS_MESH);
}

/* MSG_UBL_BUILD_COLD_MESH */
static const char* msg_ubl_build_cold_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_BUILD_COLD_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_BUILD_COLD_MESH);
	}
	return PSTR(MSG_UBL_BUILD_COLD_MESH);
}

/* MSG_UBL_MESH_HEIGHT_ADJUST */
static const char* msg_ubl_mesh_height_adjust()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MESH_HEIGHT_ADJUST);
		case 1:
			return PSTR(CN_MSG_UBL_MESH_HEIGHT_ADJUST);
	}
	return PSTR(MSG_UBL_MESH_HEIGHT_ADJUST);
}

/* MSG_UBL_MESH_HEIGHT_AMOUNT */
static const char* msg_ubl_mesh_height_amount()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MESH_HEIGHT_AMOUNT);
		case 1:
			return PSTR(CN_MSG_UBL_MESH_HEIGHT_AMOUNT);
	}
	return PSTR(MSG_UBL_MESH_HEIGHT_AMOUNT);
}

/* MSG_UBL_VALIDATE_MESH_MENU */
static const char* msg_ubl_validate_mesh_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_VALIDATE_MESH_MENU);
		case 1:
			return PSTR(CN_MSG_UBL_VALIDATE_MESH_MENU);
	}
	return PSTR(MSG_UBL_VALIDATE_MESH_MENU);
}

/* MSG_UBL_VALIDATE_PLA_MESH */
static const char* msg_ubl_validate_pla_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_VALIDATE_PLA_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_VALIDATE_PLA_MESH);
	}
	return PSTR(MSG_UBL_VALIDATE_PLA_MESH);
}

/* MSG_UBL_VALIDATE_ABS_MESH */
static const char* msg_ubl_validate_abs_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_VALIDATE_ABS_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_VALIDATE_ABS_MESH);
	}
	return PSTR(MSG_UBL_VALIDATE_ABS_MESH);
}

/* MSG_UBL_VALIDATE_CUSTOM_MESH */
static const char* msg_ubl_validate_custom_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_VALIDATE_CUSTOM_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_VALIDATE_CUSTOM_MESH);
	}
	return PSTR(MSG_UBL_VALIDATE_CUSTOM_MESH);
}

/* MSG_UBL_CONTINUE_MESH */
static const char* msg_ubl_continue_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_CONTINUE_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_CONTINUE_MESH);
	}
	return PSTR(MSG_UBL_CONTINUE_MESH);
}

/* MSG_UBL_MESH_LEVELING */
static const char* msg_ubl_mesh_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MESH_LEVELING);
		case 1:
			return PSTR(CN_MSG_UBL_MESH_LEVELING);
	}
	return PSTR(MSG_UBL_MESH_LEVELING);
}

/* MSG_UBL_3POINT_MESH_LEVELING */
static const char* msg_ubl_3point_mesh_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_3POINT_MESH_LEVELING);
		case 1:
			return PSTR(CN_MSG_UBL_3POINT_MESH_LEVELING);
	}
	return PSTR(MSG_UBL_3POINT_MESH_LEVELING);
}

/* MSG_UBL_GRID_MESH_LEVELING */
static const char* msg_ubl_grid_mesh_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_GRID_MESH_LEVELING);
		case 1:
			return PSTR(CN_MSG_UBL_GRID_MESH_LEVELING);
	}
	return PSTR(MSG_UBL_GRID_MESH_LEVELING);
}

/* MSG_UBL_MESH_LEVEL */
static const char* msg_ubl_mesh_level()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MESH_LEVEL);
		case 1:
			return PSTR(CN_MSG_UBL_MESH_LEVEL);
	}
	return PSTR(MSG_UBL_MESH_LEVEL);
}

/* MSG_UBL_SIDE_POINTS */
static const char* msg_ubl_side_points()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_SIDE_POINTS);
		case 1:
			return PSTR(CN_MSG_UBL_SIDE_POINTS);
	}
	return PSTR(MSG_UBL_SIDE_POINTS);
}

/* MSG_UBL_OUTPUT_MAP */
static const char* msg_ubl_output_map()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_OUTPUT_MAP);
		case 1:
			return PSTR(CN_MSG_UBL_OUTPUT_MAP);
	}
	return PSTR(MSG_UBL_OUTPUT_MAP);
}

/* MSG_UBL_OUTPUT_MAP_HOST */
static const char* msg_ubl_output_map_host()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_OUTPUT_MAP_HOST);
		case 1:
			return PSTR(CN_MSG_UBL_OUTPUT_MAP_HOST);
	}
	return PSTR(MSG_UBL_OUTPUT_MAP_HOST);
}

/* MSG_UBL_OUTPUT_MAP_CSV */
static const char* msg_ubl_output_map_csv()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_OUTPUT_MAP_CSV);
		case 1:
			return PSTR(CN_MSG_UBL_OUTPUT_MAP_CSV);
	}
	return PSTR(MSG_UBL_OUTPUT_MAP_CSV);
}

/* MSG_UBL_OUTPUT_MAP_BACKUP */
static const char* msg_ubl_output_map_backup()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_OUTPUT_MAP_BACKUP);
		case 1:
			return PSTR(CN_MSG_UBL_OUTPUT_MAP_BACKUP);
	}
	return PSTR(MSG_UBL_OUTPUT_MAP_BACKUP);
}

/* MSG_UBL_INFO_UBL */
static const char* msg_ubl_info_ubl()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_INFO_UBL);
		case 1:
			return PSTR(CN_MSG_UBL_INFO_UBL);
	}
	return PSTR(MSG_UBL_INFO_UBL);
}

/* MSG_UBL_EDIT_MESH_MENU */
static const char* msg_ubl_edit_mesh_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_EDIT_MESH_MENU);
		case 1:
			return PSTR(CN_MSG_UBL_EDIT_MESH_MENU);
	}
	return PSTR(MSG_UBL_EDIT_MESH_MENU);
}

/* MSG_UBL_FILLIN_AMOUNT */
static const char* msg_ubl_fillin_amount()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_FILLIN_AMOUNT);
		case 1:
			return PSTR(CN_MSG_UBL_FILLIN_AMOUNT);
	}
	return PSTR(MSG_UBL_FILLIN_AMOUNT);
}

/* MSG_UBL_FILLIN_AMOUNT */
static const char* msg_ubl_manual_fillin()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_MANUAL_FILLIN);
		case 1:
			return PSTR(CN_MSG_UBL_MANUAL_FILLIN);
	}
	return PSTR(MSG_UBL_MANUAL_FILLIN);
}

/* MSG_UBL_SMART_FILLIN */
static const char* msg_ubl_smart_fillin()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_SMART_FILLIN);
		case 1:
			return PSTR(CN_MSG_UBL_SMART_FILLIN);
	}
	return PSTR(MSG_UBL_SMART_FILLIN);
}

/* MSG_UBL_FILLIN_MESH */
static const char* msg_ubl_fillin_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_FILLIN_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_FILLIN_MESH);
	}
	return PSTR(MSG_UBL_FILLIN_MESH);
}

/* MSG_UBL_INVALIDATE_ALL */
static const char* msg_ubl_invalidate_all()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_INVALIDATE_ALL);
		case 1:
			return PSTR(CN_MSG_UBL_INVALIDATE_ALL);
	}
	return PSTR(MSG_UBL_INVALIDATE_ALL);
}

/* MSG_UBL_INVALIDATE_CLOSEST */
static const char* msg_ubl_invalidate_closest()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_INVALIDATE_CLOSEST);
		case 1:
			return PSTR(CN_MSG_UBL_INVALIDATE_CLOSEST);
	}
	return PSTR(MSG_UBL_INVALIDATE_CLOSEST);
}

/* MSG_UBL_FINE_TUNE_ALL */
static const char* msg_ubl_fine_tune_all()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_FINE_TUNE_ALL);
		case 1:
			return PSTR(CN_MSG_UBL_FINE_TUNE_ALL);
	}
	return PSTR(MSG_UBL_FINE_TUNE_ALL);
}

/* MSG_UBL_FINE_TUNE_CLOSEST */
static const char* msg_ubl_fine_tune_closest()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_FINE_TUNE_CLOSEST);
		case 1:
			return PSTR(CN_MSG_UBL_FINE_TUNE_CLOSEST);
	}
	return PSTR(MSG_UBL_FINE_TUNE_CLOSEST);
}

/* MSG_UBL_STORAGE_MESH_MENU */
static const char* msg_ubl_storage_mesh_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_STORAGE_MESH_MENU);
		case 1:
			return PSTR(CN_MSG_UBL_STORAGE_MESH_MENU);
	}
	return PSTR(MSG_UBL_STORAGE_MESH_MENU);
}

/* MSG_UBL_STORAGE_SLOT */
static const char* msg_ubl_storage_slot()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_STORAGE_SLOT);
		case 1:
			return PSTR(CN_MSG_UBL_STORAGE_SLOT);
	}
	return PSTR(MSG_UBL_STORAGE_SLOT);
}

/* MSG_UBL_LOAD_MESH */
static const char* msg_ubl_load_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_LOAD_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_LOAD_MESH);
	}
	return PSTR(MSG_UBL_LOAD_MESH);
}

/* MSG_UBL_SAVE_MESH */
static const char* msg_ubl_save_mesh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_SAVE_MESH);
		case 1:
			return PSTR(CN_MSG_UBL_SAVE_MESH);
	}
	return PSTR(MSG_UBL_SAVE_MESH);
}

/* MSG_MESH_LOADED */
static const char* msg_mesh_loaded()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MESH_LOADED);
		case 1:
			return PSTR(CN_MSG_MESH_LOADED);
	}
	return PSTR(MSG_MESH_LOADED);
}

/* MSG_MESH_SAVED */
static const char* msg_mesh_saved()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MESH_SAVED);
		case 1:
			return PSTR(CN_MSG_MESH_SAVED);
	}
	return PSTR(MSG_MESH_SAVED);
}

/* MSG_NO_STORAGE */
static const char* msg_no_storage()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NO_STORAGE);
		case 1:
			return PSTR(CN_MSG_NO_STORAGE);
	}
	return PSTR(MSG_NO_STORAGE);
}

/* MSG_UBL_STEP_BY_STEP_MENU */
static const char* msg_ubl_step_by_step_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_STEP_BY_STEP_MENU);
		case 1:
			return PSTR(CN_MSG_UBL_STEP_BY_STEP_MENU);
	}
	return PSTR(MSG_UBL_STEP_BY_STEP_MENU);
}

/* MSG_FREE_XY */
static const char* msg_free_xy()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FREE_XY);
		case 1:
			return PSTR(CN_MSG_FREE_XY);
	}
	return PSTR(MSG_FREE_XY);
}


/* MSG_MOVE_X */
static const char* msg_move_x()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_X);
		case 1:
			return PSTR(CN_MSG_MOVE_X);
	}
	return PSTR(MSG_MOVE_X);
}

/* MSG_MOVE_Y */
static const char* msg_move_y()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_Y);
		case 1:
			return PSTR(CN_MSG_MOVE_Y);
	}
	return PSTR(MSG_MOVE_Y);
}

/* MSG_MOVE_Z */
static const char* msg_move_z()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_Z);
		case 1:
			return PSTR(CN_MSG_MOVE_Z);
	}
	return PSTR(MSG_MOVE_Z);
}

/* MSG_MOVE_E */
static const char* msg_move_e()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E);
		case 1:
			return PSTR(CN_MSG_MOVE_E);
	}
	return PSTR(MSG_MOVE_E);
}

/* MSG_MOVE_E1 */
static const char* msg_move_e1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E MSG_MOVE_E1);
		case 1:
			return PSTR(CN_MSG_MOVE_E MSG_MOVE_E1);
	}
	return PSTR(MSG_MOVE_E MSG_MOVE_E1);
}

/* MSG_MOVE_E2 */
static const char* msg_move_e2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E MSG_MOVE_E2);
		case 1:
			return PSTR(CN_MSG_MOVE_E MSG_MOVE_E2);
	}
	return PSTR(MSG_MOVE_E MSG_MOVE_E2);
}

/* MSG_MOVE_E3 */
static const char* msg_move_e3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E MSG_MOVE_E3);
		case 1:
			return PSTR(CN_MSG_MOVE_E MSG_MOVE_E3);
	}
	return PSTR(MSG_MOVE_E MSG_MOVE_E3);
}

/* MSG_MOVE_E4 */
static const char* msg_move_e4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E MSG_MOVE_E4);
		case 1:
			return PSTR(CN_MSG_MOVE_E MSG_MOVE_E4);
	}
	return PSTR(MSG_MOVE_E MSG_MOVE_E4);
}

/* MSG_MOVE_E5 */
static const char* msg_move_e5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_E MSG_MOVE_E5);
		case 1:
			return PSTR(CN_MSG_MOVE_E MSG_MOVE_E5);
	}
	return PSTR(MSG_MOVE_E MSG_MOVE_E5);
}

/* MSG_MOVE_01MM */
static const char* msg_move_01mm()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_01MM);
		case 1:
			return PSTR(CN_MSG_MOVE_01MM);
	}
	return PSTR(MSG_MOVE_01MM);
}

/* MSG_MOVE_1MM */
static const char* msg_move_1mm()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_1MM);
		case 1:
			return PSTR(CN_MSG_MOVE_1MM);
	}
	return PSTR(MSG_MOVE_1MM);
}

/* MSG_MOVE_10MM */
static const char* msg_move_10mm()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOVE_10MM);
		case 1:
			return PSTR(CN_MSG_MOVE_10MM);
	}
	return PSTR(MSG_MOVE_10MM);
}

/* MSG_SPEED */
static const char* msg_speed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SPEED);
		case 1:
			return PSTR(CN_MSG_SPEED);
	}
	return PSTR(MSG_SPEED);
}

/* MSG_BED_Z */
static const char* msg_bed_z()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BED_Z);
		case 1:
			return PSTR(CN_MSG_BED_Z);
	}
	return PSTR(MSG_BED_Z);
}

/* MSG_NOZZLE */
static const char* msg_nozzle()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE);
		case 1:
			return PSTR(CN_MSG_NOZZLE);
	}
	return PSTR(MSG_NOZZLE);
}

/* MSG_NOZZLE1 */
static const char* msg_nozzle1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE MSG_N1);
		case 1:
			return PSTR(CN_MSG_NOZZLE MSG_N1);
	}
	return PSTR(MSG_NOZZLE MSG_N1);
}

/* MSG_NOZZLE2 */
static const char* msg_nozzle2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE MSG_N2);
		case 1:
			return PSTR(CN_MSG_NOZZLE MSG_N2);
	}
	return PSTR(MSG_NOZZLE MSG_N2);
}

/* MSG_NOZZLE3 */
static const char* msg_nozzle3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE MSG_N3);
		case 1:
			return PSTR(CN_MSG_NOZZLE MSG_N3);
	}
	return PSTR(MSG_NOZZLE MSG_N3);
}

/* MSG_NOZZLE4 */
static const char* msg_nozzle4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE MSG_N4);
		case 1:
			return PSTR(CN_MSG_NOZZLE MSG_N4);
	}
	return PSTR(MSG_NOZZLE MSG_N4);
}

/* MSG_NOZZLE5 */
static const char* msg_nozzle5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NOZZLE MSG_N5);
		case 1:
			return PSTR(CN_MSG_NOZZLE MSG_N5);
	}
	return PSTR(MSG_NOZZLE MSG_N5);
}

/* MSG_BED */
static const char* msg_bed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BED);
		case 1:
			return PSTR(CN_MSG_BED);
	}
	return PSTR(MSG_BED);
}

/* MSG_FAN_SPEED */
static const char* msg_fan_speed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FAN_SPEED);
		case 1:
			return PSTR(CN_MSG_FAN_SPEED);
	}
	return PSTR(MSG_FAN_SPEED);
}

/* MSG_FAN_SPEED MSG_N2 */
static const char* msg_fan_speed2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FAN_SPEED MSG_N2);
		case 1:
			return PSTR(CN_MSG_FAN_SPEED MSG_N2);
	}
	return PSTR(MSG_FAN_SPEED MSG_N2);
}

/* MSG_FAN_SPEED MSG_N3 */
static const char* msg_fan_speed3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FAN_SPEED MSG_N3);
		case 1:
			return PSTR(CN_MSG_FAN_SPEED MSG_N3);
	}
	return PSTR(MSG_FAN_SPEED MSG_N3);
}

/* MSG_FLOW */
static const char* msg_flow()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW);
		case 1:
			return PSTR(CN_MSG_FLOW);
	}
	return PSTR(MSG_FLOW);
}

/* MSG_FLOW1 */
static const char* msg_flow1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW MSG_N1);
		case 1:
			return PSTR(CN_MSG_FLOW MSG_N1);
	}
	return PSTR(MSG_FLOW MSG_N1);
}

/* MSG_FLOW2 */
static const char* msg_flow2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW MSG_N2);
		case 1:
			return PSTR(CN_MSG_FLOW MSG_N2);
	}
	return PSTR(MSG_FLOW MSG_N2);
}

/* MSG_FLOW3 */
static const char* msg_flow3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW MSG_N3);
		case 1:
			return PSTR(CN_MSG_FLOW MSG_N3);
	}
	return PSTR(MSG_FLOW MSG_N3);
}

/* MSG_FLOW4 */
static const char* msg_flow4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW MSG_N4);
		case 1:
			return PSTR(CN_MSG_FLOW MSG_N4);
	}
	return PSTR(MSG_FLOW MSG_N4);
}

/* MSG_FLOW5 */
static const char* msg_flow5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FLOW MSG_N5);
		case 1:
			return PSTR(CN_MSG_FLOW MSG_N5);
	}
	return PSTR(MSG_FLOW MSG_N5);
}

/* MSG_CONTROL */
static const char* msg_control()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL);
		case 1:
			return PSTR(CN_MSG_CONTROL);
	}
	return PSTR(MSG_CONTROL);
}

/* MSG_MIN */
static const char* msg_min()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MIN);
		case 1:
			return PSTR(CN_MSG_MIN);
	}
	return PSTR(MSG_MIN);
}

/* MSG_MAX */
static const char* msg_max()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MAX);
		case 1:
			return PSTR(CN_MSG_MAX);
	}
	return PSTR(MSG_MAX);
}

/* MSG_FACTOR */
static const char* msg_factor()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FACTOR);
		case 1:
			return PSTR(CN_MSG_FACTOR);
	}
	return PSTR(MSG_FACTOR);
}

/* MSG_AUTOTEMP */
static const char* msg_autotemp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTOTEMP);
		case 1:
			return PSTR(CN_MSG_AUTOTEMP);
	}
	return PSTR(MSG_AUTOTEMP);
}

/* MSG_ON */
static const char* msg_on()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ON);
		case 1:
			return PSTR(CN_MSG_ON);
	}
	return PSTR(MSG_ON);
}

/* MSG_OFF */
static const char* msg_off()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_OFF);
		case 1:
			return PSTR(CN_MSG_OFF);
	}
	return PSTR(MSG_OFF);
}

/* MSG_PID_P */
static const char* msg_pid_p()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PID_P);
		case 1:
			return PSTR(CN_MSG_PID_P);
	}
	return PSTR(MSG_PID_P);
}

/* MSG_PID_I */
static const char* msg_pid_i()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PID_I);
		case 1:
			return PSTR(CN_MSG_PID_I);
	}
	return PSTR(MSG_PID_I);
}

/* MSG_PID_D */
static const char* msg_pid_d()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PID_D);
		case 1:
			return PSTR(CN_MSG_PID_D);
	}
	return PSTR(MSG_PID_D);
}

/* MSG_PID_C */
static const char* msg_pid_c()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PID_C);
		case 1:
			return PSTR(CN_MSG_PID_C);
	}
	return PSTR(MSG_PID_C);
}

/* MSG_SELECT */
static const char* msg_select()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SELECT);
		case 1:
			return PSTR(CN_MSG_SELECT);
	}
	return PSTR(MSG_SELECT);
}

/* MSG_SELECT MSG_E1*/
static const char* msg_select1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SELECT MSG_E1);
		case 1:
			return PSTR(CN_MSG_SELECT MSG_E1);
	}
	return PSTR(MSG_SELECT MSG_E1);
}

/* MSG_SELECT MSG_E2*/
static const char* msg_select2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SELECT MSG_E2);
		case 1:
			return PSTR(CN_MSG_SELECT MSG_E2);
	}
	return PSTR(MSG_SELECT MSG_E2);
}

/* MSG_ACC */
static const char* msg_acc()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ACC);
		case 1:
			return PSTR(CN_MSG_ACC);
	}
	return PSTR(MSG_ACC);
}

/* MSG_JERK */
static const char* msg_jerk()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_JERK);
		case 1:
			return PSTR(CN_MSG_JERK);
	}
	return PSTR(MSG_JERK);
}

/* MSG_VX_JERK */
static const char* msg_vx_jerk()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VX_JERK);
		case 1:
			return PSTR(CN_MSG_VX_JERK);
	}
	return PSTR(MSG_VX_JERK);
}

/* MSG_VY_JERK */
static const char* msg_vy_jerk()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VY_JERK);
		case 1:
			return PSTR(CN_MSG_VY_JERK);
	}
	return PSTR(MSG_VY_JERK);
}

/* MSG_VZ_JERK */
static const char* msg_vz_jerk()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VZ_JERK);
		case 1:
			return PSTR(CN_MSG_VZ_JERK);
	}
	return PSTR(MSG_VZ_JERK);
}

/* MSG_VE_JERK */
static const char* msg_ve_jerk()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VE_JERK);
		case 1:
			return PSTR(CN_MSG_VE_JERK);
	}
	return PSTR(MSG_VE_JERK);
}

/* MSG_VMAXX */
static const char* msg_vmaxx()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_X);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_X);
	}
	return PSTR(MSG_VMAX MSG_X);
}

/* MSG_VMAXY */
static const char* msg_vmaxy()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_Y);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_Y);
	}
	return PSTR(MSG_VMAX MSG_Y);
}

/* MSG_VMAXZ */
static const char* msg_vmaxz()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_Z);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_Z);
	}
	return PSTR(MSG_VMAX MSG_Z);
}

/* MSG_VMAXE */
static const char* msg_vmaxe()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E);
	}
	return PSTR(MSG_VMAX MSG_E);
}

/* MSG_VMAXE1 */
static const char* msg_vmaxe1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E1);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E1);
	}
	return PSTR(MSG_VMAX MSG_E1);
}

/* MSG_VMAXE2 */
static const char* msg_vmaxe2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E2);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E2);
	}
	return PSTR(MSG_VMAX MSG_E2);
}

/* MSG_VMAXE3 */
static const char* msg_vmaxe3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E3);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E3);
	}
	return PSTR(MSG_VMAX MSG_E3);
}

/* MSG_VMAXE4 */
static const char* msg_vmaxe4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E4);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E4);
	}
	return PSTR(MSG_VMAX MSG_E4);
}

/* MSG_VMAXE5 */
static const char* msg_vmaxe5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMAX MSG_E5);
		case 1:
			return PSTR(CN_MSG_VMAX MSG_E5);
	}
	return PSTR(MSG_VMAX MSG_E5);
}

/* MSG_VELOCITY */
static const char* msg_velocity()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VELOCITY);
		case 1:
			return PSTR(CN_MSG_VELOCITY);
	}
	return PSTR(MSG_VELOCITY);
}

/* MSG_VMIN */
static const char* msg_vmin()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VMIN);
		case 1:
			return PSTR(CN_MSG_VMIN);
	}
	return PSTR(MSG_VMIN);
}

/* MSG_VTRAV_MIN */
static const char* msg_vtrav_min()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VTRAV_MIN);
		case 1:
			return PSTR(CN_MSG_VTRAV_MIN);
	}
	return PSTR(MSG_VTRAV_MIN);
}

/* MSG_ACCELERATION */
static const char* msg_acceleration()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ACCELERATION);
		case 1:
			return PSTR(CN_MSG_ACCELERATION);
	}
	return PSTR(MSG_ACCELERATION);
}

/* MSG_AMAXX */
static const char* msg_amaxx()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_X);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_X);
	}
	return PSTR(MSG_AMAX MSG_X);
}

/* MSG_AMAXY */
static const char* msg_amaxy()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_Y);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_Y);
	}
	return PSTR(MSG_AMAX MSG_Y);
}

/* MSG_AMAXZ */
static const char* msg_amaxz()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_Z);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_Z);
	}
	return PSTR(MSG_AMAX MSG_Z);
}

/* MSG_AMAXE */
static const char* msg_amaxe()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E);
	}
	return PSTR(MSG_AMAX MSG_E);
}

/* MSG_AMAXE1 */
static const char* msg_amaxe1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E1);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E1);
	}
	return PSTR(MSG_AMAX MSG_E1);
}

/* MSG_AMAXE2 */
static const char* msg_amaxe2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E2);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E2);
	}
	return PSTR(MSG_AMAX MSG_E2);
}

/* MSG_AMAXE3 */
static const char* msg_amaxe3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E3);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E3);
	}
	return PSTR(MSG_AMAX MSG_E3);
}

/* MSG_AMAXE4 */
static const char* msg_amaxe4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E4);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E4);
	}
	return PSTR(MSG_AMAX MSG_E4);
}

/* MSG_AMAXE5 */
static const char* msg_amaxe5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AMAX MSG_E5);
		case 1:
			return PSTR(CN_MSG_AMAX MSG_E5);
	}
	return PSTR(MSG_AMAX MSG_E5);
}

/* MSG_A_RETRACT */
static const char* msg_a_retract()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_A_RETRACT);
		case 1:
			return PSTR(CN_MSG_A_RETRACT);
	}
	return PSTR(MSG_A_RETRACT);
}

/* MSG_A_TRAVEL */
static const char* msg_a_travel()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_A_TRAVEL);
		case 1:
			return PSTR(CN_MSG_A_TRAVEL);
	}
	return PSTR(MSG_A_TRAVEL);
}

/* MSG_STEPS_PER_MM */
static const char* msg_steps_per_mm()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_STEPS_PER_MM);
		case 1:
			return PSTR(CN_MSG_STEPS_PER_MM);
	}
	return PSTR(MSG_STEPS_PER_MM);
}

/* MSG_XSTEPS */
static const char* msg_xsteps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_XSTEPS);
		case 1:
			return PSTR(CN_MSG_XSTEPS);
	}
	return PSTR(MSG_XSTEPS);
}

/* MSG_YSTEPS */
static const char* msg_ysteps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_YSTEPS);
		case 1:
			return PSTR(CN_MSG_YSTEPS);
	}
	return PSTR(MSG_YSTEPS);
}

/* MSG_ZSTEPS */
static const char* msg_zsteps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ZSTEPS);
		case 1:
			return PSTR(CN_MSG_ZSTEPS);
	}
	return PSTR(MSG_ZSTEPS);
}

/* MSG_ESTEPS */
static const char* msg_esteps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ESTEPS);
		case 1:
			return PSTR(CN_MSG_ESTEPS);
	}
	return PSTR(MSG_ESTEPS);
}

/* MSG_E1STEPS */
static const char* msg_e1steps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E1STEPS);
		case 1:
			return PSTR(CN_MSG_E1STEPS);
	}
	return PSTR(MSG_E1STEPS);
}

/* MSG_E2STEPS */
static const char* msg_e2steps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E2STEPS);
		case 1:
			return PSTR(CN_MSG_E2STEPS);
	}
	return PSTR(MSG_E2STEPS);
}

/* MSG_E3STEPS */
static const char* msg_e3steps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E3STEPS);
		case 1:
			return PSTR(CN_MSG_E3STEPS);
	}
	return PSTR(MSG_E3STEPS);
}

/* MSG_E4STEPS */
static const char* msg_e4steps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E4STEPS);
		case 1:
			return PSTR(CN_MSG_E4STEPS);
	}
	return PSTR(MSG_E4STEPS);
}

/* MSG_E5STEPS */
static const char* msg_e5steps()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E5STEPS);
		case 1:
			return PSTR(CN_MSG_E4STEPS);
	}
	return PSTR(MSG_E5STEPS);
}

/* MSG_TEMPERATURE */
static const char* msg_temperature()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_TEMPERATURE);
		case 1:
			return PSTR(CN_MSG_TEMPERATURE);
	}
	return PSTR(MSG_TEMPERATURE);
}

/* MSG_MOTION */
static const char* msg_motion()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MOTION);
		case 1:
			return PSTR(CN_MSG_MOTION);
	}
	return PSTR(MSG_MOTION);
}

/* MSG_FILAMENT */
static const char* msg_filament()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT);
		case 1:
			return PSTR(CN_MSG_FILAMENT);
	}
	return PSTR(MSG_FILAMENT);
}

/* MSG_VOLUMETRIC_ENABLED */
static const char* msg_volumetric_enabled()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_VOLUMETRIC_ENABLED);
		case 1:
			return PSTR(CN_MSG_VOLUMETRIC_ENABLED);
	}
	return PSTR(MSG_VOLUMETRIC_ENABLED);
}

/* MSG_FILAMENT_DIAM */
static const char* msg_filament_diam()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM);
	}
	return PSTR(MSG_FILAMENT_DIAM);
}

/* MSG_FILAMENT_DIAM1 */
static const char* msg_filament_diam1()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E1);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM MSG_DIAM_E1);
	}
	return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E1);
}

/* MSG_FILAMENT_DIAM2 */
static const char* msg_filament_diam2()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E2);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM MSG_DIAM_E2);
	}
	return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E2);
}

/* MSG_FILAMENT_DIAM3 */
static const char* msg_filament_diam3()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E3);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM MSG_DIAM_E3);
	}
	return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E3);
}

/* MSG_FILAMENT_DIAM4 */
static const char* msg_filament_diam4()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E4);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM MSG_DIAM_E4);
	}
	return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E4);
}

/* MSG_FILAMENT_DIAM5 */
static const char* msg_filament_diam5()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E5);
		case 1:
			return PSTR(CN_MSG_FILAMENT_DIAM MSG_DIAM_E5);
	}
	return PSTR(MSG_FILAMENT_DIAM MSG_DIAM_E5);
}

/* MSG_ADVANCE_K */
static const char* msg_advance_k()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ADVANCE_K);
		case 1:
			return PSTR(CN_MSG_ADVANCE_K);
	}
	return PSTR(MSG_ADVANCE_K);
}

/* MSG_CONTRAST */
static const char* msg_contrast()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTRAST);
		case 1:
			return PSTR(CN_MSG_CONTRAST);
	}
	return PSTR(MSG_CONTRAST);
}

/* MSG_STORE_EEPROM */
static const char* msg_store_eeprom()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_STORE_EEPROM);
		case 1:
			return PSTR(CN_MSG_STORE_EEPROM);
	}
	return PSTR(MSG_STORE_EEPROM);
}

/* MSG_LOAD_EEPROM */
static const char* msg_load_eeprom()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LOAD_EEPROM);
		case 1:
			return PSTR(CN_MSG_LOAD_EEPROM);
	}
	return PSTR(MSG_LOAD_EEPROM);
}

/* MSG_RESTORE_FAILSAFE */
static const char* msg_restore_failsafe()
{
	switch (currentfontnameindex) 
	{
		case 0:
			return PSTR(MSG_RESTORE_FAILSAFE);
		case 1:
			return PSTR(CN_MSG_RESTORE_FAILSAFE);
	}
	return PSTR(MSG_RESTORE_FAILSAFE);
}

/* MSG_INIT_EEPROM */
static const char* msg_init_eeprom()
{
	switch (currentfontnameindex) 
	{
		case 0:
			return PSTR(MSG_INIT_EEPROM);
		case 1:
			return PSTR(CN_MSG_INIT_EEPROM);
	}
	return PSTR(MSG_INIT_EEPROM);
}

/* MSG_REFRESH */
static const char* msg_refresh()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_REFRESH);
		case 1:
			return PSTR(CN_MSG_REFRESH);
	}
	return PSTR(MSG_REFRESH);
}

/* MSG_WATCH */
static const char* msg_watch()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_WATCH);
		case 1:
			return PSTR(CN_MSG_WATCH);
	}
	return PSTR(MSG_WATCH);
}

/* MSG_PREPARE */
static const char* msg_prepare()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PREPARE);
		case 1:
			return PSTR(CN_MSG_PREPARE);
	}
	return PSTR(MSG_PREPARE);
}

/* MSG_TUNE */
static const char* msg_tune()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_TUNE);
		case 1:
			return PSTR(CN_MSG_TUNE);
	}
	return PSTR(MSG_TUNE);
}

/* MSG_PAUSE_PRINT */
static const char* msg_pause_print()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PAUSE_PRINT);
		case 1:
			return PSTR(CN_MSG_PAUSE_PRINT);
	}
	return PSTR(MSG_PAUSE_PRINT);
}

/* MSG_RESUME_PRINT */
static const char* msg_resume_print()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_RESUME_PRINT);
		case 1:
			return PSTR(CN_MSG_RESUME_PRINT);
	}
	return PSTR(MSG_RESUME_PRINT);
}

/* MSG_STOP_PRINT */
static const char* msg_stop_print()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_STOP_PRINT);
		case 1:
			return PSTR(CN_MSG_STOP_PRINT);
	}
	return PSTR(MSG_STOP_PRINT);
}

/* MSG_CARD_MENU */
static const char* msg_card_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CARD_MENU);
		case 1:
			return PSTR(CN_MSG_CARD_MENU);
	}
	return PSTR(MSG_CARD_MENU);
}

/* MSG_NO_CARD */
static const char* msg_no_card()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NO_CARD);
		case 1:
			return PSTR(CN_MSG_NO_CARD);
	}
	return PSTR(MSG_NO_CARD);
}

/* MSG_DWELL */
static const char* msg_dwell()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DWELL);
		case 1:
			return PSTR(CN_MSG_DWELL);
	}
	return PSTR(MSG_DWELL);
}

/* MSG_USERWAIT */
static const char* msg_userwait()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_USERWAIT);
		case 1:
			return PSTR(CN_MSG_USERWAIT);
	}
	return PSTR(MSG_USERWAIT);
}

/* MSG_RESUMING */
static const char* msg_resuming()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_RESUMING);
		case 1:
			return PSTR(CN_MSG_RESUMING);
	}
	return PSTR(MSG_RESUMING);
}

/* MSG_PRINT_ABORTED */
static const char* msg_print_aborted()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_PRINT_ABORTED);
		case 1:
			return PSTR(CN_MSG_PRINT_ABORTED);
	}
	return PSTR(MSG_PRINT_ABORTED);
}

/* MSG_NO_MOVE */
static const char* msg_no_move()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_NO_MOVE);
		case 1:
			return PSTR(CN_MSG_NO_MOVE);
	}
	return PSTR(MSG_NO_MOVE);
}

/* MSG_KILLED */
static const char* msg_killed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_KILLED);
		case 1:
			return PSTR(CN_MSG_KILLED);
	}
	return PSTR(MSG_KILLED);
}

/* MSG_STOPPED */
static const char* msg_stopped()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_STOPPED);
		case 1:
			return PSTR(CN_MSG_STOPPED);
	}
	return PSTR(MSG_STOPPED);
}

/* MSG_CONTROL_RETRACT */
static const char* msg_control_retract()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT);
	}
	return PSTR(MSG_CONTROL_RETRACT);
}

/* MSG_CONTROL_RETRACT_SWAP */
static const char* msg_control_retract_swap()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT_SWAP);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT_SWAP);
	}
	return PSTR(MSG_CONTROL_RETRACT_SWAP);
}

/* MSG_CONTROL_RETRACTF */
static const char* msg_control_retractf()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACTF);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACTF);
	}
	return PSTR(MSG_CONTROL_RETRACTF);
}

/* MSG_CONTROL_RETRACT_ZLIFT */
static const char* msg_control_retract_zlift()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT_ZLIFT);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT_ZLIFT);
	}
	return PSTR(MSG_CONTROL_RETRACT_ZLIFT);
}

/* MSG_CONTROL_RETRACT_RECOVER */
static const char* msg_control_retract_recover()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT_RECOVER);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT_RECOVER);
	}
	return PSTR(MSG_CONTROL_RETRACT_RECOVER);
}

/* MSG_CONTROL_RETRACT_RECOVER_SWAP */
static const char* msg_control_retract_recover_swap()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT_RECOVER_SWAP);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT_RECOVER_SWAP);
	}
  return PSTR(MSG_CONTROL_RETRACT_RECOVER_SWAP);
}

/* MSG_CONTROL_RETRACT_RECOVERF */
static const char* msg_control_retract_recoverf()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CONTROL_RETRACT_RECOVERF);
		case 1:
			return PSTR(CN_MSG_CONTROL_RETRACT_RECOVERF);
	}
	return PSTR(MSG_CONTROL_RETRACT_RECOVERF);
}

/* MSG_AUTORETRACT */
static const char* msg_autoretract()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_AUTORETRACT);
		case 1:
			return PSTR(CN_MSG_AUTORETRACT);
	}
	return PSTR(MSG_AUTORETRACT);
}

/* MSG_FILAMENTCHANGE */
static const char* msg_filamentchange()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENTCHANGE);
		case 1:
			return PSTR(CN_MSG_FILAMENTCHANGE);
	}
	return PSTR(MSG_FILAMENTCHANGE);
}

/* MSG_INIT_SDCARD */
static const char* msg_init_sdcard()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INIT_SDCARD);
		case 1:
			return PSTR(CN_MSG_INIT_SDCARD);
	}
	return PSTR(MSG_INIT_SDCARD);
}

/* MSG_CNG_SDCARD */
static const char* msg_cng_sdcard()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CNG_SDCARD);
		case 1:
			return PSTR(CN_MSG_CNG_SDCARD);
	}
	return PSTR(MSG_CNG_SDCARD);
}

/* MSG_ZPROBE_OUT */
static const char* msg_zprobe_out()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ZPROBE_OUT);
		case 1:
			return PSTR(CN_MSG_ZPROBE_OUT);
	}
	return PSTR(MSG_ZPROBE_OUT);
}

/* MSG_BLTOUCH */
static const char* msg_bltouch()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH);
		case 1:
			return PSTR(CN_MSG_BLTOUCH);
	}
	return PSTR(MSG_BLTOUCH);
}

/* MSG_BLTOUCH_SELFTEST */
static const char* msg_bltouch_selftest()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_SELFTEST);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_SELFTEST);
	}
	return PSTR(MSG_BLTOUCH_SELFTEST);
}

/* MSG_BLTOUCH_RESET */
static const char* msg_bltouch_reset()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_RESET);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_RESET);
	}
	return PSTR(MSG_BLTOUCH_RESET);
}

/* MSG_BLTOUCH_DEPLOY */
static const char* msg_bltouch_deploy()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_DEPLOY);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_DEPLOY);
	}
	return PSTR(MSG_BLTOUCH_DEPLOY);
}

/* MSG_BLTOUCH_STOW */
static const char* msg_bltouch_stow()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_STOW);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_STOW);
	}
	return PSTR(MSG_BLTOUCH_STOW);
}

/* MSG_BLTOUCH_SW_MODE */
static const char* msg_bltouch_sw_mode()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_SW_MODE);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_SW_MODE);
	}
	return PSTR(MSG_BLTOUCH_SW_MODE);
}

/* MSG_BLTOUCH_5V_MODE */
static const char* msg_bltouch_5v_mode()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_5V_MODE);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_5V_MODE);
	}
	return PSTR(MSG_BLTOUCH_5V_MODE);
}

/* MSG_BLTOUCH_OD_MODE */
static const char* msg_bltouch_od_mode()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BLTOUCH_OD_MODE);
		case 1:
			return PSTR(CN_MSG_BLTOUCH_OD_MODE);
	}
	return PSTR(MSG_BLTOUCH_OD_MODE);
}


/* MSG_HOME */
static const char* msg_home()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_HOME);
		case 1:
			return PSTR(CN_MSG_HOME);
	}
	return PSTR(MSG_HOME);
}

/* MSG_FIRST */
static const char* msg_first()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FIRST);
		case 1:
			return PSTR(CN_MSG_FIRST);
	}
	return PSTR(MSG_FIRST);
}

/* MSG_ZPROBE_ZOFFSET */
static const char* msg_zprobe_zoffset()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ZPROBE_ZOFFSET);
		case 1:
			return PSTR(CN_MSG_ZPROBE_ZOFFSET);
	}
	return PSTR(MSG_ZPROBE_ZOFFSET);
}

/* MSG_BABYSTEP_X */
static const char* msg_babystep_x()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BABYSTEP_X);
		case 1:
			return PSTR(CN_MSG_BABYSTEP_X);
	}
	return PSTR(MSG_BABYSTEP_X);
}

/* MSG_BABYSTEP_Y */
static const char* msg_babystep_y()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BABYSTEP_Y);
		case 1:
			return PSTR(CN_MSG_BABYSTEP_Y);
	}
	return PSTR(MSG_BABYSTEP_Y);
}

/* MSG_BABYSTEP_Z */
static const char* msg_babystep_z()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BABYSTEP_Z);
		case 1:
			return PSTR(CN_MSG_BABYSTEP_Z);
	}
	return PSTR(MSG_BABYSTEP_Z);
}

/* MSG_ENDSTOP_ABORT */
static const char* msg_endstop_abort()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ENDSTOP_ABORT);
		case 1:
			return PSTR(CN_MSG_ENDSTOP_ABORT);
	}
	return PSTR(MSG_ENDSTOP_ABORT);
}

/* MSG_HEATING_FAILED_LCD */
static const char* msg_heating_failed_lcd()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_HEATING_FAILED_LCD);
		case 1:
    		return PSTR(CN_MSG_HEATING_FAILED_LCD);
	}
	return PSTR(MSG_HEATING_FAILED_LCD);
}

/* MSG_ERR_REDUNDANT_TEMP */
static const char* msg_err_redundant_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ERR_REDUNDANT_TEMP);
		case 1:
			return PSTR(CN_MSG_ERR_REDUNDANT_TEMP);
	}
	return PSTR(MSG_ERR_REDUNDANT_TEMP);
}

/* MSG_THERMAL_RUNAWAY */
static const char* msg_thermal_runaway()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_THERMAL_RUNAWAY);
		case 1:
			return PSTR(CN_MSG_THERMAL_RUNAWAY);
	}
	return PSTR(MSG_THERMAL_RUNAWAY);
}

/* MSG_ERR_MAXTEMP */
static const char* msg_err_maxtemp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ERR_MAXTEMP);
		case 1:
			return PSTR(CN_MSG_ERR_MAXTEMP);
	}
	return PSTR(MSG_ERR_MAXTEMP);
}

/* MSG_ERR_MINTEMP */
static const char* msg_err_mintemp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ERR_MINTEMP);
		case 1:
			return PSTR(CN_MSG_ERR_MINTEMP);
	}
	return PSTR(MSG_ERR_MINTEMP);
}

/* MSG_ERR_MAXTEMP_BED */
static const char* msg_err_maxtemp_bed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ERR_MAXTEMP_BED);
		case 1:
			return PSTR(CN_MSG_ERR_MAXTEMP_BED);
	}
	return PSTR(MSG_ERR_MAXTEMP_BED);
}

/* MSG_ERR_MINTEMP_BED */
static const char* msg_err_mintemp_bed()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ERR_MINTEMP_BED);
		case 1:
			return PSTR(MSG_ERR_MINTEMP_BED);
	}
	return PSTR(MSG_ERR_MINTEMP_BED);
}

/* MSG_DELTA_SETTINGS */
static const char* msg_delta_settings()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_SETTINGS);
		case 1:
			return PSTR(CN_MSG_DELTA_SETTINGS);
	}
	return PSTR(MSG_DELTA_SETTINGS);
}

/* MSG_DELTA_AUTO_CALIBRATE */
static const char* msg_delta_auto_calibrate()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_AUTO_CALIBRATE);
		case 1:
			return PSTR(CN_MSG_DELTA_AUTO_CALIBRATE);
	}
	return PSTR(MSG_DELTA_AUTO_CALIBRATE);
}

/* MSG_DELTA_HEIGHT_CALIBRATE */
static const char* msg_delta_height_calibrate()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_HEIGHT_CALIBRATE);
		case 1:
			return PSTR(CN_MSG_DELTA_HEIGHT_CALIBRATE);
	}
	return PSTR(MSG_DELTA_HEIGHT_CALIBRATE);
}

/* MSG_DELTA_DIAG_ROG */
static const char* msg_delta_diag_rog()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_DIAG_ROG);
		case 1:
			return PSTR(CN_MSG_DELTA_DIAG_ROG);
	}
	return PSTR(MSG_DELTA_DIAG_ROG);
}

/* MSG_DELTA_HEIGHT */
static const char* msg_delta_height()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_HEIGHT);
		case 1:
			return PSTR(CN_MSG_DELTA_HEIGHT);
	}
	return PSTR(MSG_DELTA_HEIGHT);
}

/* MSG_DELTA_RADIUS */
static const char* msg_delta_radius()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DELTA_RADIUS);
		case 1:
			return PSTR(CN_MSG_DELTA_RADIUS);
	}
	return PSTR(MSG_DELTA_RADIUS);
}

/* MSG_INFO_MENU */
static const char* msg_info_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_MENU);
		case 1:
			return PSTR(CN_MSG_INFO_MENU);
	}
	return PSTR(MSG_INFO_MENU);
}

/* MSG_INFO_PRINTER_MENU */
static const char* msg_info_printer_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PRINTER_MENU);
		case 1:
			return PSTR(CN_MSG_INFO_PRINTER_MENU);
	}
	return PSTR(MSG_INFO_PRINTER_MENU);
}

/* MSG_WEBSITE_URL_MENU */
static const char* msg_website_url_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_WEBSITE_URL_MENU);
		case 1:
			return PSTR(CN_MSG_WEBSITE_URL_MENU);
	}
	return PSTR(MSG_WEBSITE_URL_MENU);
}

/* MSG_3POINT_LEVELING */
static const char* msg_3point_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_3POINT_LEVELING);
		case 1:
			return PSTR(CN_MSG_3POINT_LEVELING);
	}
	return PSTR(MSG_3POINT_LEVELING);
}

/* MSG_LINEAR_LEVELING */
static const char* msg_linear_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_LINEAR_LEVELING);
		case 1:
			return PSTR(CN_MSG_LINEAR_LEVELING);
	}
	return PSTR(MSG_LINEAR_LEVELING);
}

/* MSG_BILINEAR_LEVELING */
static const char* msg_bilinear_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_BILINEAR_LEVELING);
		case 1:
			return PSTR(CN_MSG_BILINEAR_LEVELING);
	}
	return PSTR(MSG_BILINEAR_LEVELING);
}

/* MSG_UBL_LEVELING */
static const char* msg_ubl_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_UBL_LEVELING);
		case 1:
			return PSTR(CN_MSG_UBL_LEVELING);
	}
	return PSTR(MSG_UBL_LEVELING);
}

/* MSG_MESH_LEVELING */
static const char* msg_mesh_leveling()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_MESH_LEVELING);
		case 1:
			return PSTR(CN_MSG_MESH_LEVELING);
	}
	return PSTR(MSG_UBL_LEVELING);
}

/* MSG_INFO_STATS_MENU */
static const char* msg_info_stats_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_STATS_MENU);
		case 1:
			return PSTR(CN_MSG_INFO_STATS_MENU);
	}
	return PSTR(MSG_INFO_STATS_MENU);
}

/* MSG_INFO_BOARD_MENU */
static const char* msg_info_board_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_BOARD_MENU);
		case 1:
			return PSTR(CN_MSG_INFO_BOARD_MENU);
	}
	return PSTR(MSG_INFO_BOARD_MENU);
}

/* MSG_INFO_THERMISTOR_MENU */
static const char* msg_info_thermistor_menu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_THERMISTOR_MENU);
		case 1:
			return PSTR(CN_MSG_INFO_THERMISTOR_MENU);
	}
	return PSTR(MSG_INFO_THERMISTOR_MENU);
}

/* MSG_INFO_EXTRUDERS */
static const char* msg_info_extruders()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_EXTRUDERS MSG_N1);
		case 1:
			return PSTR(CN_MSG_INFO_EXTRUDERS MSG_N1);
	}
	return PSTR(MSG_INFO_EXTRUDERS MSG_N1);
}

/* MSG_INFO_BAUDRATE */
static const char* msg_info_baudrate()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_BAUDRATE MSG_BAUDRATE);
		case 1:
			return PSTR(CN_MSG_INFO_BAUDRATE MSG_BAUDRATE);
	}
	return PSTR(MSG_INFO_BAUDRATE MSG_BAUDRATE);
}

/* MSG_INFO_PROTOCOL */
static const char* msg_info_protocol()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PROTOCOL);
		case 1:
			return PSTR(CN_MSG_INFO_PROTOCOL);
	}
	return PSTR(MSG_INFO_PROTOCOL);
}

/* MSG_CASE_LIGHT */
static const char* msg_case_light()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CASE_LIGHT);
		case 1:
			return PSTR(CN_MSG_CASE_LIGHT);
	}
	return PSTR(MSG_CASE_LIGHT);
}

/* MSG_CASE_LIGHT */
static const char* msg_case_light_brightness()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CASE_LIGHT_BRIGHTNESS);
		case 1:
			return PSTR(CN_MSG_CASE_LIGHT_BRIGHTNESS);
	}
	return PSTR(MSG_CASE_LIGHT_BRIGHTNESS);
}

/* MSG_INFO_PRINT_COUNT */
static const char* msg_info_print_count()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PRINT_COUNT);
		case 1:
			return PSTR(CN_MSG_INFO_PRINT_COUNT);
	}
	return PSTR(MSG_INFO_PRINT_COUNT);
}

/* MSG_INFO_COMPLETED_PRINTS */
static const char* msg_info_completed_prints()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_COMPLETED_PRINTS);
		case 1:
			return PSTR(CN_MSG_INFO_COMPLETED_PRINTS);
	}
	return PSTR(MSG_INFO_COMPLETED_PRINTS);
}

/* MSG_INFO_PRINT_TIME */
static const char* msg_info_print_time()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PRINT_TIME);
		case 1:
			return PSTR(CN_MSG_INFO_PRINT_TIME);
	}
	return PSTR(MSG_INFO_PRINT_TIME);
}

/* MSG_INFO_PRINT_LONGEST */
static const char* msg_info_print_longest()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PRINT_LONGEST);
		case 1:
			return PSTR(CN_MSG_INFO_PRINT_LONGEST);
	}
	return PSTR(MSG_INFO_PRINT_LONGEST);
}

/* MSG_INFO_PRINT_FILAMENT */
static const char* msg_info_print_filament()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PRINT_FILAMENT);
		case 1:
			return PSTR(CN_MSG_INFO_PRINT_FILAMENT);
	}
	return PSTR(MSG_INFO_PRINT_FILAMENT);
}

/* MSG_INFO_MIN_TEMP */
static const char* msg_info_min_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_MIN_TEMP);
		case 1:
			return PSTR(CN_MSG_INFO_MIN_TEMP);
	}
	return PSTR(MSG_INFO_MIN_TEMP);
}

/* MSG_INFO_MAX_TEMP */
static const char* msg_info_max_temp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_MAX_TEMP);
		case 1:
			return PSTR(CN_MSG_INFO_MAX_TEMP);
	}
	return PSTR(MSG_INFO_MAX_TEMP);
}

/* MSG_INFO_PSU */
static const char* msg_info_psu()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_INFO_PSU);
		case 1:
			return PSTR(CN_MSG_INFO_PSU);
	}
	return PSTR(MSG_INFO_PSU);
}

/* MSG_DRIVE_STRENGTH */
static const char* msg_drive_strength()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DRIVE_STRENGTH);
		case 1:
			return PSTR(CN_MSG_DRIVE_STRENGTH);
	}
	return PSTR(MSG_DRIVE_STRENGTH);
}

/* MSG_X MSG_DRIVE_STRENGTH */
static const char* msg_drive_strengthx()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_X MSG_DAC_PERCENT);
		case 1:
			return PSTR(MSG_X CN_MSG_DAC_PERCENT);
	}
	return PSTR(MSG_X MSG_DAC_PERCENT);
}

/* MSG_Y MSG_DRIVE_STRENGTH */
static const char* msg_drive_strengthy()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_Y MSG_DAC_PERCENT);
		case 1:
			return PSTR(MSG_Y CN_MSG_DAC_PERCENT);
	}
	return PSTR(MSG_Y MSG_DAC_PERCENT);
}

/* MSG_Z MSG_DRIVE_STRENGTH */
static const char* msg_drive_strengthz()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_Z MSG_DAC_PERCENT);
		case 1:
			return PSTR(MSG_Z CN_MSG_DAC_PERCENT);
	}
	return PSTR(MSG_Z MSG_DAC_PERCENT);
}

/* MSG_E MSG_DRIVE_STRENGTH */
static const char* msg_drive_strengthe()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_E MSG_DAC_PERCENT);
		case 1:
			return PSTR(MSG_E CN_MSG_DAC_PERCENT);
	}
	return PSTR(MSG_E MSG_DAC_PERCENT);
}

/* MSG_DAC_EEPROM_WRITE */
static const char* msg_dac_eeprom_write()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_DAC_EEPROM_WRITE);
		case 1:
			return PSTR(CN_MSG_DAC_EEPROM_WRITE);
	}
	return PSTR(MSG_DAC_EEPROM_WRITE);
}

/* MSG_FILAMENT_CHANGE_HEADER */
static const char* msg_filament_change_header()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_HEADER);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_HEADER);
	}
	return PSTR(MSG_FILAMENT_CHANGE_HEADER);
}

/* MSG_FILAMENT_CHANGE_OPTION_HEADER */
static const char* msg_filament_change_option_header()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_OPTION_HEADER);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_OPTION_HEADER);
	}
	return PSTR(MSG_FILAMENT_CHANGE_OPTION_HEADER);
}

/* MSG_FILAMENT_CHANGE_OPTION_EXTRUDE */
static const char* msg_filament_change_option_extrude()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_OPTION_EXTRUDE);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_OPTION_EXTRUDE);
	}
	return PSTR(MSG_FILAMENT_CHANGE_OPTION_EXTRUDE);
}

/* MSG_FILAMENT_CHANGE_OPTION_RESUME */
static const char* msg_filament_change_option_resume()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_OPTION_RESUME);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_OPTION_RESUME);
	}
	return PSTR(MSG_FILAMENT_CHANGE_OPTION_RESUME);
}

/* MSG_FILAMENT_CHANGE_MINTEMP */
static const char* msg_filament_change_mintemp()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_MINTEMP MSG_EXTRUDE_MINTEMP);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_MINTEMP MSG_EXTRUDE_MINTEMP);
	}
	return PSTR(MSG_FILAMENT_CHANGE_MINTEMP MSG_EXTRUDE_MINTEMP);
}

/* MSG_FILAMENT_CHANGE_NOZZLE */
static const char* msg_filament_change_nozzle()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_FILAMENT_CHANGE_NOZZLE);
		case 1:
			return PSTR(CN_MSG_FILAMENT_CHANGE_NOZZLE);
	}
	return PSTR(MSG_FILAMENT_CHANGE_NOZZLE);
}

/* MSG_SELECT_LANGUAGE */
static const char* msg_select_language()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_SELECT_LANGUAGE);
		case 1:
			return PSTR(CN_MSG_SELECT_LANGUAGE);
	}
	return PSTR(MSG_SELECT_LANGUAGE);
}

/* MSG_ENGLISH_LANGUAGE */
static const char* msg_english_lang()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_ENGLISH_LANGUAGE);
		case 1:
			return PSTR(CN_MSG_ENGLISH_LANGUAGE);
	}
	return PSTR(MSG_ENGLISH_LANGUAGE);
}

/* MSG_CHINESE_LANGUAGE */
static const char* msg_chinese_lang()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_CHINESE_LANGUAGE);
		case 1:
			return PSTR(CN_MSG_CHINESE_LANGUAGE);
	}
	return PSTR(MSG_CHINESE_LANGUAGE);
}

/* MSG_POWER_LOSS_RECOVERY */
static const char* msg_power_loss_recovery()
{
	switch (currentfontnameindex)
	{
		case 0:
			return PSTR(MSG_POWER_LOSS_RECOVERY);
		case 1:
			return PSTR(CN_MSG_POWER_LOSS_RECOVERY);
	}
	return PSTR(MSG_POWER_LOSS_RECOVERY);
}

#endif		// __LANGUAGE_H
