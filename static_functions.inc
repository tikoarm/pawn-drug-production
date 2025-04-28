static pan_object[2], pan_fill_object[2], pan_nitro_object[2], pan_fill_amount[2], pan_owner[2];

#define COOKING_RANGES_AMOUNT   14
enum cooking_range_types
{
    crt_pan,
    crt_water
};
enum cooking_ranges_enum
{
    Float:cr_x,
    Float:cr_y,
    Float:cr_z,
    Float:cr_rx,
    Float:cr_ry,
    Float:cr_rz,

    cr_objectid
};
static cooking_ranges[COOKING_RANGES_AMOUNT][2][cooking_ranges_enum];

enum gCooking_Range_enum
{
    Float:gcr_x,
    Float:gcr_y,
    Float:gcr_z,

    Text3D:gcr_info,
    gcr_owner,
    gcr_amount
};
static gCooking_Range[COOKING_RANGES_AMOUNT][gCooking_Range_enum];
static cooking_ranges_total;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#define MAX_DRUGS_TRAY_AMOUNT 12
enum drugs_tray_enum
{
    Float:trayX,
    Float:trayY,
    Float:trayZ,
    Float:trayRX,
    Float:trayRY,
    Float:trayRZ,

    trayObjectID
};
static drugs_tray[MAX_DRUGS_TRAY_AMOUNT][4][drugs_tray_enum];

enum tray_types
{
    drugtray_null,

    drugtray1_takeit,
    drugtray2_ontable
}
enum gDrugs_tray_enum
{
    Text3D:gTrayInfo,
    gTrayOwner,
    gTrayType,
    gTrayTimer,
    gTrayAmount
};
static gDrugs_Tray[MAX_DRUGS_TRAY_AMOUNT][gDrugs_tray_enum];
static drugs_tray_amount;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#define DRUGS_FRIDGE_AMOUNT   14
enum fridge_types
{
    fridge_null,

    fridge_freezeprocess,
    fridge_takeit
};
enum drugs_fridge_enum
{
    Float:f_x,
    Float:f_y,
    Float:f_z,

    Text3D:f_info,
    f_owner,
    f_type,
    f_timer
};
static fridgeinfo[DRUGS_FRIDGE_AMOUNT][drugs_fridge_enum];
static fridge_total;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
stock null_pan(id, init = 0)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "null_pan(id:%i, init = %i)", id, init);
    #endif
    if(id == -1) return 0;

    if(init != 1)
    {
        if(pan_object[id] != 0) destroy_pan_object(id, 0);
        if(pan_fill_object[id] != 0) destroy_pan_object(id, 1);
    }
    
    pan_object[id] = 
    pan_fill_object[id] = 
    pan_nitro_object[id] = 
    pan_fill_amount[id] = 0;

    pan_owner[id] = INVALID_PLAYER_ID;

    UpdateDynamicVarkaText(id);
    return 1;
}
stock destroy_pan_object(id, type)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "1 | destroy_pan_object(id:%i, type = %i) | pan_object = %i, pan_fill_object = %i, pan_nitro_object = %i", id, type, pan_object[id], pan_fill_object[id], pan_nitro_object[id]);
    #endif

    switch(type)
    {
        case 0:
        {
            DestroyDynamicObject(pan_object[id]);
            pan_object[id] = 0;

            if(pan_nitro_object[id] != 0) DestroyDynamicObject(pan_nitro_object[id]), pan_nitro_object[id] = 0;
        }
        case 1:
        {
            DestroyDynamicObject(pan_fill_object[id]);
            pan_fill_object[id] = 0;
        }
    }
    UpdateDynamicVarkaText(id);
    return 1;
}
stock create_pan_object(id, type)
{
    switch(id)
    {
        case 0:
        {
            switch(type)
            {
                case 0: 
                {
                    if(pan_object[id] != 0) return 1;
                    pan_object[id] = CreateDynamicObject(19585, 1805.992431, 1334.523315, 1016.467651, 0.000014, 0.000007, 179.999832, -1, 28, -1, 300.00, 300.00);
                    pan_nitro_object[id] = CreateDynamicObject(18699, 1805.981201, 1334.743041, 1014.867004, 0.000000, 0.000007, 179.999862, -1, 28, -1, 300.00, 300.00);
                }
                case 1:
                {
                    if(pan_fill_object[id] != 0) return 1;

                    if(pan_nitro_object[id] != 0) DestroyDynamicObject(pan_nitro_object[id]), pan_nitro_object[id] = 0;
                    pan_fill_object[id] = CreateDynamicObject(2243, 1805.992431, 1334.743530, 1016.297424, 0.000014, 0.000007, 179.999832, -1, 28, -1, 300.00, 300.00);
                    SetDynamicObjectMaterial(pan_fill_object[id], 0, 19480, "signsurf", "sign", 0x00000000);
                    SetDynamicObjectMaterial(pan_fill_object[id], 1, 18646, "matcolours", "lightblue", 0x00000000);
                }
            }
        }

        case 1:
        {
            switch(type)
            {
                case 0: 
                {
                    if(pan_object[id] != 0) return 1;
                    pan_object[id] = CreateDynamicObject(19585, 1814.247558, 1333.857421, 1016.467651, 0.000000, -0.000014, 179.999908, -1, 28, -1, 300.00, 300.00);
                    pan_nitro_object[id] = CreateDynamicObject(18699, 1814.248901, 1334.072387, 1014.867004, 0.000006, 0.000007, -0.000165, -1, 28, -1, 300.00, 300.00);
                }
                case 1:
                {
                    if(pan_fill_object[id] != 0) return 1;

                    if(pan_nitro_object[id] != 0) DestroyDynamicObject(pan_nitro_object[id]), pan_nitro_object[id] = 0;
                    pan_fill_object[id] = CreateDynamicObject(2243, 1814.237670, 1334.061279, 1016.297424, 0.000014, 0.000007, -0.000165, -1, 28, -1, 300.00, 300.00); //Смесь №2
                    SetDynamicObjectMaterial(pan_fill_object[id], 0, 19480, "signsurf", "sign", 0x00000000);
                    SetDynamicObjectMaterial(pan_fill_object[id], 1, 18646, "matcolours", "lightblue", 0x00000000);
                }
            }
        }
    }
    UpdateDynamicVarkaText(id);
    return 1;
}

stock create_cooking_range(id, type)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "1 | create_cooking_range(id:%i, type = %i) | crt_pan-cr_objectid = %i, crt_water-cr_objectid = %i", id, type, cooking_ranges[id][crt_pan][cr_objectid], cooking_ranges[id][crt_water][cr_objectid]);
    #endif
    switch(type)
    {
        case 0:
        {
            if(cooking_ranges[id][crt_pan][cr_objectid] != 0) return 1;
            cooking_ranges[id][crt_pan][cr_objectid] = CreateDynamicObject(19585, cooking_ranges[id][crt_pan][cr_x], cooking_ranges[id][crt_pan][cr_y], cooking_ranges[id][crt_pan][cr_z], cooking_ranges[id][crt_pan][cr_rx], cooking_ranges[id][crt_pan][cr_ry], cooking_ranges[id][crt_pan][cr_rz], -1, 28, -1, 300.00, 300.00); 
        }
        case 1:
        {
            if(cooking_ranges[id][crt_pan][cr_objectid] == 0) return 1;
            if(cooking_ranges[id][crt_water][cr_objectid] != 0) return 1;

            cooking_ranges[id][crt_water][cr_objectid] = CreateDynamicObject(2243, cooking_ranges[id][crt_water][cr_x], cooking_ranges[id][crt_water][cr_y], cooking_ranges[id][crt_water][cr_z], cooking_ranges[id][crt_water][cr_rx], cooking_ranges[id][crt_water][cr_ry], cooking_ranges[id][crt_water][cr_rz], -1, 28, -1, 300.00, 300.00); 
            SetDynamicObjectMaterial(cooking_ranges[id][crt_water][cr_objectid], 0, 19480, "signsurf", "sign", 0x00000000);
            SetDynamicObjectMaterial(cooking_ranges[id][crt_water][cr_objectid], 1, 18646, "matcolours", "lightblue", 0x00000000);
        }
    }
    UpdateCookingRangeText(id);
    return 1;
}
stock destroy_cooking_range(id, type)
{
    switch(type)
    {
        case 0:
        {
            if(cooking_ranges[id][crt_pan][cr_objectid] == 0) return 1;

            DestroyDynamicObject(cooking_ranges[id][crt_pan][cr_objectid]);
            cooking_ranges[id][crt_pan][cr_objectid] = 0;
        }
        case 1:
        {
            if(cooking_ranges[id][crt_water][cr_objectid] == 0) return 1;

            DestroyDynamicObject(cooking_ranges[id][crt_water][cr_objectid]);
            cooking_ranges[id][crt_water][cr_objectid] = 0;
        }
    }
    UpdateCookingRangeText(id);
    return 1;
}
stock UpdateDynamicVarkaText(id)
{
    #if devmode == true
    new string[512];
    #else
    new string[256];
    #endif

    format(string, sizeof(string), ""drp"Точка Наполнения {F07427}№%i\n\n", id + 1);
    if(pan_owner[id] == INVALID_PLAYER_ID) strcat(string, ""wh"Для того чтобы занять стенд, нажмите "drp"L.Alt");
    else
    {
        format(string, sizeof(string), "%s"wh"Занято: "drp"%s[%i]\n", string, Name(pan_owner[id]), pan_owner[id]);

        if(pan_fill_object[id] == 0)
        {
            format(string, sizeof(string), "%s"wh"Процесс наполнения вещества\n\
            "wh"Прогресс: "drp"%i / %i", string, pan_fill_amount[id], SECONDS_FOR_PAN_TO_BEREADY);
        }
        else
        {
            format(string, sizeof(string), "%s"wh"Заберите вещество, пока оно не испортилось!\n\
            "wh"Оставшееся время: "drp"%i сек", string, pan_fill_amount[id]);
        }
    }
    
    #if devmode == true
    format(string, sizeof(string), "%s\n\n\n"drp"developer:\n"wh"", string);
    format(string, sizeof(string), "%s"drp"pan_object[%i] "wh"= %i\n", string, id, pan_object[id]);
    format(string, sizeof(string), "%s"drp"pan_fill_object[%i] "wh"= %i\n", string, id, pan_fill_object[id]);
    format(string, sizeof(string), "%s"drp"pan_nitro_object[%i] "wh"= %i\n", string, id, pan_nitro_object[id]);
    #endif
    UpdateDynamic3DTextLabelText(TochkaVarki[id], -1, string);
    return 1;
}
stock player_pressed_alt_on_pan(playerid, number)
{
    new id;
    if(number == 14) id = 0;
    else if(number == 15) id = 1;
    if(pan_owner[id] != INVALID_PLAYER_ID) return error(playerid, "Данный стенд уже занят!");

    switch(number)
    {
        case 14: if(get_drugs_tableid(playerid) != 1) return error(playerid, "Вы начали работу за другим столом!");
        case 15: if(get_drugs_tableid(playerid) != 2) return error(playerid, "Вы начали работу за другим столом!");
    }

    pan_owner[id] = playerid;
    pan_fill_amount[id] = 0;
    create_pan_object(id, 0);
    Streamer_Update(playerid);

    set_drugs_step(playerid, 5);
    send_drugs_help_message(playerid);
    return 1;
}

stock Drugs_Timer()
{
    for(new id = 0; id <= 1; id++)
    {
        if(pan_owner[id] == INVALID_PLAYER_ID) continue;
        if(pan_object[id] == 0) continue;

        if(pan_fill_object[id] == 0) // Все еще длится процесс приготовления
        {
            pan_fill_amount[id] += 2;
            if(pan_fill_amount[id] >= SECONDS_FOR_PAN_TO_BEREADY)
            {
                pan_fill_amount[id] = SECONDS_FOR_PAN_TO_TAKE;
                create_pan_object(id, 1);

                Streamer_Update(pan_owner[id]);
                set_drugs_step(pan_owner[id], 6);
                send_drugs_help_message(pan_owner[id]);
            }
        }
        else
        {
            pan_fill_amount[id]--;
            if(pan_fill_amount[id] <= 0) 
            {
                set_drugs_step(pan_owner[id], 0);
                error(pan_owner[id], "Вы не успели забрать кастрюлю!");
                send_drugs_help_message(pan_owner[id]);
                Streamer_Update(pan_owner[id]);

                null_pan(id);
                continue;
            }
        }

        UpdateDynamicVarkaText(id);
    }

    for(new id = 0; id < cooking_ranges_total; id++)
    {
        if(gCooking_Range[id][gcr_owner] != INVALID_PLAYER_ID)
        {
            #if devmode == true
            gCooking_Range[id][gcr_amount] += VYAZKOST_V_SECUNDU * 2 + 1;
            #else
            gCooking_Range[id][gcr_amount] += VYAZKOST_V_SECUNDU;
            #endif

            if(gCooking_Range[id][gcr_amount] >= DRUGS_DELETE_VYAZKA) 
            { 
                set_drugs_step(gCooking_Range[id][gcr_owner], 0);
                error(gCooking_Range[id][gcr_owner], "Вы не успели забрать кастрюлю!");
                send_drugs_help_message(gCooking_Range[id][gcr_owner]);

                null_cooking_range(id);
                continue; 
            }
            if(gCooking_Range[id][gcr_amount] == DRUGS_MAXIMAL_VYAZKA)
            {
                SendTipp(gCooking_Range[id][gcr_owner], "Смесь готова, заберите ее как можно скорее!");
                set_drugs_step(gCooking_Range[id][gcr_owner], 9);
            }
            UpdateCookingRangeText(id);
        }
    }

    for(new id = 0; id < drugs_tray_amount; id++)
    {
        if(gDrugs_Tray[id][gTrayOwner] != INVALID_PLAYER_ID)
        {
            switch(gDrugs_Tray[id][gTrayType])
            {
                case drugtray1_takeit:
                {
                    gDrugs_Tray[id][gTrayTimer]--;
                    if(gDrugs_Tray[id][gTrayTimer] <= 0) {
                        set_drugs_step(gDrugs_Tray[id][gTrayOwner], 0);
                        error(gDrugs_Tray[id][gTrayOwner], "Вы не успели забрать поднос!");
                        send_drugs_help_message(gDrugs_Tray[id][gTrayOwner]);

                        null_drug_tray(id);
                        continue;
                    }
                }
                case drugtray2_ontable:
                {
                    gDrugs_Tray[id][gTrayTimer]--;
                    if(gDrugs_Tray[id][gTrayTimer] <= 0) {
                        set_drugs_step(gDrugs_Tray[id][gTrayOwner], 0);
                        error(gDrugs_Tray[id][gTrayOwner], "Вы не успели разбить лёд!");
                        send_drugs_help_message(gDrugs_Tray[id][gTrayOwner]);

                        null_drug_tray(id);
                        continue;
                    }
                }
            }
            UpdateDrugTrayText(id);
        }
    }

    for(new id = 0; id < fridge_total; id++)
    {
        if(fridgeinfo[id][f_owner] != INVALID_PLAYER_ID)
        {
            switch(fridgeinfo[id][f_type])
            {
                case fridge_freezeprocess:
                {
                    fridgeinfo[id][f_timer]--;
                    if(fridgeinfo[id][f_timer] <= 0) {
                        set_drugs_step(fridgeinfo[id][f_owner], 14);
                        send_drugs_help_message(fridgeinfo[id][f_owner]);
                        fridgeinfo[id][f_type] = fridge_takeit;
                        fridgeinfo[id][f_timer] = FRIDGE_TAKEIT_SEC;
                        continue;
                    }
                }
                case fridge_takeit:
                {
                    fridgeinfo[id][f_timer]--;
                    if(fridgeinfo[id][f_timer] <= 0) {
                        set_drugs_step(fridgeinfo[id][f_owner], 0);
                        error(fridgeinfo[id][f_owner], "Вы не успели забрать поднос!");
                        send_drugs_help_message(fridgeinfo[id][f_owner]);

                        null_fridge(id);
                        continue;
                    }
                }
            }
            UpdateFridgeText(id);
        }
    }
    return 1;
}
stock IsPlayerRentingDrugsPan(playerid)
{
    if(pan_owner[0] == playerid) return 0;
    else if(pan_owner[1] == playerid) return 1;
    return -1;
}

stock add_cooking_range(id, type, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(id >= COOKING_RANGES_AMOUNT) return print("add_cooking_range limit error");
    if(type >= 2) return print("add_cooking_range max type error");
    if(type <= -1) return print("add_cooking_range min type error");

    cooking_ranges[id][type][cr_x] = x;
    cooking_ranges[id][type][cr_y] = y;
    cooking_ranges[id][type][cr_z] = z;
    cooking_ranges[id][type][cr_rx] = rx;
    cooking_ranges[id][type][cr_ry] = ry;
    cooking_ranges[id][type][cr_rz] = rz;

    if(!type)
    {
        gCooking_Range[id][gcr_x] = x;
        gCooking_Range[id][gcr_y] = y;
        gCooking_Range[id][gcr_z] = z;

        switch(id + 1)
        {
            case 0..7: x += 0.45, z += 0.5;
            case 8..14: x += 0.05, z += 0.5;
        }
        
        gCooking_Range[id][gcr_info] = CreateDynamic3DTextLabel("text", -1, x, y, z, COOKING_RANGE_3D_METERS, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, DRUGSHOP_VW, DRUGSHOP_INT);
        UpdateCookingRangeText(id);

        #if devmode == true
        printf("Created CreateDynamic3DTextLabel on %f %f %f with number %i", x, y, z, id);
        #endif
    }
    return 1;
}
stock UpdateCookingRangeText(id)
{
    #if devmode == true
    new string[512];
    #else
    new string[256];
    #endif

    format(string, sizeof(string), ""drp"Точка Варки {F07427}№%i\n\n", id + 1);
    if(gCooking_Range[id][gcr_owner] == INVALID_PLAYER_ID) strcat(string, ""wh"Для занятия варочной поверхности\nИспользуйте "drp"L.Alt");
    else
    {
        new percent_color[16];
        switch(gCooking_Range[id][gcr_amount])
        {
            case 0..40: percent_color = "F4CA16";
            case 41..60: percent_color = "F07427";
            case 61..95: percent_color = "50C878";
            case 96..105: percent_color = "008000";
            case 106..DRUGS_DELETE_VYAZKA: percent_color = "cd1c18";
            default: percent_color = "cd1c18";
        }
        format(string, sizeof(string), "%s"wh"Химик: "drp"%s[%i]\n\
        "wh"Процент необходимой вязкости: {%s}%i", 
        string, Name(gCooking_Range[id][gcr_owner]), gCooking_Range[id][gcr_owner], percent_color, gCooking_Range[id][gcr_amount]);
    }
    
    #if devmode == true
    format(string, sizeof(string), "%s\n\n\n"drp"developer:\n"wh"", string);
    #endif
    UpdateDynamic3DTextLabelText(gCooking_Range[id][gcr_info], -1, string);
    return 1;
}
stock cooking_ranges_init()
{
    cooking_ranges_total = 0;
    for(new i = 0; i < COOKING_RANGES_AMOUNT; i++) {
        for(new g = 0; g < 2; g++) {
            cooking_ranges[i][g][cr_objectid] = 0;
        }
        null_cooking_range(i, 1);
    }
    
    add_cooking_range(cooking_ranges_total, crt_pan, 1807.845581, 1314.235107, 1016.577758, 0.000029, 0.000000, 89.999908);
    add_cooking_range(cooking_ranges_total, crt_water, 1808.065795, 1314.235107, 1016.407531, 0.000029, 0.000000, 89.999908);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1806.345336, 1314.235107, 1016.577758, 0.000045, 0.000000, 89.999862);
    add_cooking_range(cooking_ranges_total, crt_water, 1806.565551, 1314.235107, 1016.407531, 0.000045, 0.000000, 89.999862);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1804.845214, 1314.235107, 1016.577758, 0.000050, 0.000000, 89.999839);
    add_cooking_range(cooking_ranges_total, crt_water, 1805.065429, 1314.235107, 1016.407531, 0.000050, 0.000000, 89.999839);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1803.355102, 1314.235107, 1016.577758, 0.000037, 0.000000, 89.999885);
    add_cooking_range(cooking_ranges_total, crt_water, 1803.575317, 1314.235107, 1016.407531, 0.000037, 0.000000, 89.999885);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1801.854858, 1314.235107, 1016.577758, 0.000050, 0.000000, 89.999839);
    add_cooking_range(cooking_ranges_total, crt_water, 1802.075073, 1314.235107, 1016.407531, 0.000050, 0.000000, 89.999839);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1800.354736, 1314.235107, 1016.577758, 0.000059, 0.000000, 89.999816);
    add_cooking_range(cooking_ranges_total, crt_water, 1800.574951, 1314.235107, 1016.407531, 0.000059, 0.000000, 89.999816);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1798.853637, 1314.235107, 1016.577758, 0.000068, 0.000000, 89.999794);
    add_cooking_range(cooking_ranges_total, crt_water, 1799.073852, 1314.235107, 1016.407531, 0.000068, 0.000000, 89.999794);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1808.095825, 1329.087646, 1016.577758, 0.000037, 0.000000, 89.999885);
    add_cooking_range(cooking_ranges_total, crt_water, 1808.316040, 1329.087646, 1016.407531, 0.000037, 0.000000, 89.999885);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1806.595581, 1329.087646, 1016.577758, 0.000050, 0.000000, 89.999839);
    add_cooking_range(cooking_ranges_total, crt_water, 1806.815795, 1329.087646, 1016.407531, 0.000050, 0.000000, 89.999839);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1805.095458, 1329.087646, 1016.577758, 0.000059, 0.000000, 89.999816);
    add_cooking_range(cooking_ranges_total, crt_water, 1805.315673, 1329.087646, 1016.407531, 0.000059, 0.000000, 89.999816);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1803.605346, 1329.087646, 1016.577758, 0.000045, 0.000000, 89.999862);
    add_cooking_range(cooking_ranges_total, crt_water, 1803.825561, 1329.087646, 1016.407531, 0.000045, 0.000000, 89.999862);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1802.105102, 1329.087646, 1016.577758, 0.000059, 0.000000, 89.999816);
    add_cooking_range(cooking_ranges_total, crt_water, 1802.325317, 1329.087646, 1016.407531, 0.000059, 0.000000, 89.999816);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1800.604980, 1329.087646, 1016.577758, 0.000068, 0.000000, 89.999794);
    add_cooking_range(cooking_ranges_total, crt_water, 1800.825195, 1329.087646, 1016.407531, 0.000068, 0.000000, 89.999794);
    cooking_ranges_total++;

    add_cooking_range(cooking_ranges_total, crt_pan, 1799.103881, 1329.087646, 1016.577758, 0.000075, 0.000000, 89.999771);
    add_cooking_range(cooking_ranges_total, crt_water, 1799.324096, 1329.087646, 1016.407531, 0.000075, 0.000000, 89.999771);
    cooking_ranges_total++;
    return 1;
}
stock staticdrugs_alt(playerid)
{
    if(!get_drugs_step(playerid)) return 1;

    switch(get_drugs_step(playerid))
    {
        case 7:
        {
            new id = get_closest_cooking_range(playerid);
            if(id == -1) return 1;

            gCooking_Range[id][gcr_amount] = 0;
            gCooking_Range[id][gcr_owner] = playerid;

            RemovePlayerAttachedObject(playerid, 1);
            RemovePlayerAttachedObject(playerid, 2);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

            create_cooking_range(id, 0);
            create_cooking_range(id, 1);
            Streamer_Update(playerid);

            set_drugs_step(playerid, 8);
            send_drugs_help_message(playerid);
        }
        case 9:
        {
            new id = get_closest_cooking_range(playerid);
            if(IsPlayerRentingCook(playerid) != id) return error(playerid, "Подойдите к своему столу!");
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_CARRY);

		    RemovePlayerAttachedObject(playerid, 1);
            RemovePlayerAttachedObject(playerid, 2);
            SetPlayerAttachedObject(playerid, 1, 19585, 4, 0.272998, -0.317999, -0.054000, 19.099998, -98.200012, 86.100013, 0.851998, 0.864998, 0.726999);
            SetPlayerAttachedObject(playerid, 2, 19580, 4, 0.290997, -0.389998, 0.121999, 3.799999, 80.499984, 2.899996, 0.585997, 0.561998, 0.594000);

            null_cooking_range(id);

            Streamer_Update(playerid);
            set_drugs_step(playerid, 10);
            send_drugs_help_message(playerid);
        }
        case 10:
        {
            new id = get_closest_drugs_tray(playerid);
            if(id == -1) return 1;

            gDrugs_Tray[id][gTrayTimer] = 10;
            gDrugs_Tray[id][gTrayType] = drugtray1_takeit;
            gDrugs_Tray[id][gTrayOwner] = playerid;

            RemovePlayerAttachedObject(playerid, 1);
            RemovePlayerAttachedObject(playerid, 2);
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_NONE);

            create_drug_tray(id, 777);
            Streamer_Update(playerid);

            set_drugs_step(playerid, 11);
            send_drugs_help_message(playerid);
        }
        case 11:
        {
            new id = get_closest_drugs_tray(playerid);
            if(IsPlayerRentingDrugsTray(playerid) != id) return error(playerid, "Подойдите к своему столу!");

            null_drug_tray(id);
            Streamer_Update(playerid);
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_CARRY);
            SetPlayerAttachedObject(playerid, 1, 19809, 5, 0.133999, 0.063999, 0.143000, -81.299606, 3.399996, 14.000029, 1.000000, 1.000000, 1.000000, 0x0, 0x0);
            SetPlayerAttachedObject(playerid, 2, 19827, 6, 0.101000, 0.115999, -0.195000, -18.099971, -11.500021, 0.800001, 1.536004, 1.886025, 1.925009, 0xFF00C0FF, 0x0);
            
            set_drugs_step(playerid, 12);
            send_drugs_help_message(playerid);
        }

        case 12:
        {
            new id = get_closest_fridge(playerid);
            if(id == -1) return 1;
            
            fridgeinfo[id][f_owner] = playerid;
            fridgeinfo[id][f_type] = fridge_freezeprocess;
            fridgeinfo[id][f_timer] = FRIDGE_FREEZEPROCESS_SEC;
            RemovePlayerAttachedObject(playerid, 1);
            RemovePlayerAttachedObject(playerid, 2);
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_NONE);

            set_drugs_step(playerid, 13);
            send_drugs_help_message(playerid);
            UpdateFridgeText(id);
        }
        //---------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------
        case 14:
        {
            new id = get_closest_fridge(playerid);
            if(IsPlayerRentingFridge(playerid) != id) return error(playerid, "Подойдите к своему холодильнику!");
            
            null_fridge(id);
            Streamer_Update(playerid);
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_CARRY);
            SetPlayerAttachedObject(playerid, 1, 19809, 5, 0.133999, 0.063999, 0.143000, -81.299606, 3.399996, 14.000029, 1.000000, 1.000000, 1.000000, 0x0, 0x0);
            SetPlayerAttachedObject(playerid, 2, 19827, 6, 0.101000, 0.115999, -0.195000, -18.099971, -11.500021, 0.800001, 1.536004, 1.886025, 1.925009, 0xFF00C0FF, 0x0);

            set_drugs_step(playerid, 15);
            send_drugs_help_message(playerid);
        }
        case 15:
        {
            new id = get_closest_drugs_tray(playerid);
            if(id == -1) return 1;

            gDrugs_Tray[id][gTrayTimer] = DRUGTRAY_2_WORKTIME_SEC;
            gDrugs_Tray[id][gTrayAmount] = 0;
            gDrugs_Tray[id][gTrayType] = drugtray2_ontable;
            gDrugs_Tray[id][gTrayOwner] = playerid;
            RemovePlayerAttachedObject(playerid, 1);
            RemovePlayerAttachedObject(playerid, 2);
            SetPlayerSpecialAction (playerid, SPECIAL_ACTION_NONE);
            SetPlayerAttachedObject(playerid, 1, 18635, 4, 0.544999, 0.000000, 0.000000, 112.099983, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);

            create_drug_tray(id, 777);
            Streamer_Update(playerid);

            set_drugs_step(playerid, 16);
            send_drugs_help_message(playerid);
        }
        case 16:
        {
            new id = get_closest_drugs_tray(playerid);
            if(IsPlayerRentingDrugsTray(playerid) != id) return error(playerid, "Подойдите к своему столу!");

            if(get_drugs_antiflood(playerid) > unixtime) return Tipp(playerid, "Не флудите! Попробуйте через %s", ConvertInGame(get_drugs_antiflood(playerid) - unixtime));
            set_drugs_antiflood(playerid, unixtime + DRUGTRAY_2_KD_SEC);

            DrugTray_AfterHit(playerid, id);
        }
        default: return 1;
    }
    return 1;
}

stock get_closest_cooking_range(playerid)
{
    new Float:distance = 1000.0, Float:tempdistance = 0;
    new result = -1;
    for(new i = 0; i < cooking_ranges_total; i++)
    {
        tempdistance = GetPlayerDistanceFromPoint(playerid, gCooking_Range[i][gcr_x], gCooking_Range[i][gcr_y], gCooking_Range[i][gcr_z]);
        if(tempdistance > 1.0) continue;
        if(gCooking_Range[i][gcr_owner] != INVALID_PLAYER_ID)
        {
            if(gCooking_Range[i][gcr_owner] != playerid) continue;
        }

        if(tempdistance < distance)
        {
            distance = tempdistance;
            result = i;
        }
    }
    return result;
}

stock null_cooking_range(id, init = 0)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "null_cooking_range(id:%i, init = %i)", id, init);
    #endif
    if(id == -1) return 1;

    if(init != 1)
    {
        destroy_cooking_range(id, 0);
        destroy_cooking_range(id, 1);
    }

    gCooking_Range[id][gcr_owner] = INVALID_PLAYER_ID;
    gCooking_Range[id][gcr_amount] = 0;

    UpdateCookingRangeText(id);
    return 1;
}
stock IsPlayerRentingCook(playerid)
{
    for(new i = 0; i < cooking_ranges_total; i++)
    {
        if(gCooking_Range[i][gcr_owner] == playerid) return i;
    }
    return -1;
}


///////////////////////////////////////////////
stock drug_tray_init()
{
    drugs_tray_amount = 0;
    for(new i = 0; i < MAX_DRUGS_TRAY_AMOUNT; i++) {
        for(new g = 0; g < 4; g++) {
            drugs_tray[i][g][trayObjectID] = 0;
        }
        null_drug_tray(i);
    }
    
    add_drug_tray(drugs_tray_amount, 0, 1807.483520, 1325.461181, 1016.358642, 89.999992, 450.000000, -89.999977);
    add_drug_tray(drugs_tray_amount, 1, 1807.483520, 1325.631103, 1016.358642, 90.000000, 450.000000, 270.000000);
    add_drug_tray(drugs_tray_amount, 2, 1807.543579, 1325.461181, 1016.358642, 89.999992, 450.000000, -89.999969);
    add_drug_tray(drugs_tray_amount, 3, 1807.543579, 1325.631103, 1016.358642, 89.999992, 450.000000, -89.999977);
    drugs_tray_amount++;

    add_drug_tray(drugs_tray_amount, 0, 1805.866333, 1325.634887, 1016.358642, 89.999992, 539.901123, 0.098898);
    add_drug_tray(drugs_tray_amount, 1, 1805.866333, 1325.464965, 1016.358642, 89.999992, 539.934020, 0.065913);
    add_drug_tray(drugs_tray_amount, 2, 1805.806274, 1325.634887, 1016.358642, 89.999992, 539.901123, 0.098898);
    add_drug_tray(drugs_tray_amount, 3, 1805.806274, 1325.464965, 1016.358642, 89.999992, 539.901123, 0.098898);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1802.505737, 1325.463134, 1016.358642, 89.999992, 616.605773, 103.394203);
    add_drug_tray(drugs_tray_amount, 1, 1802.505737, 1325.633056, 1016.358642, 89.999992, 616.616088, 103.383888);
    add_drug_tray(drugs_tray_amount, 2, 1802.565795, 1325.463134, 1016.358642, 89.999992, 616.605773, 103.394203);
    add_drug_tray(drugs_tray_amount, 3, 1802.565795, 1325.633056, 1016.358642, 89.999992, 616.605773, 103.394203);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1800.878784, 1325.636840, 1016.358642, 89.999992, 450.000091, 89.999984);
    add_drug_tray(drugs_tray_amount, 1, 1800.878784, 1325.466918, 1016.358642, 89.999992, 450.000061, 89.999984);
    add_drug_tray(drugs_tray_amount, 2, 1800.818725, 1325.636840, 1016.358642, 89.999992, 450.000122, 89.999984);
    add_drug_tray(drugs_tray_amount, 3, 1800.818725, 1325.466918, 1016.358642, 89.999992, 450.000091, 89.999984);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1807.483520, 1321.661376, 1016.358642, 89.999992, 450.000000, -89.999969);
    add_drug_tray(drugs_tray_amount, 1, 1807.483520, 1321.831298, 1016.358642, 89.999992, 450.000000, -89.999977);
    add_drug_tray(drugs_tray_amount, 2, 1807.543579, 1321.661376, 1016.358642, 89.999992, 450.000000, -89.999961);
    add_drug_tray(drugs_tray_amount, 3, 1807.543579, 1321.831298, 1016.358642, 89.999992, 450.000000, -89.999969);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1805.866333, 1321.827636, 1016.358642, 89.999992, 584.934020, -44.934055);
    add_drug_tray(drugs_tray_amount, 1, 1805.866333, 1321.657714, 1016.358642, 89.999992, 584.934020, -44.934055);
    add_drug_tray(drugs_tray_amount, 2, 1805.806274, 1321.827636, 1016.358642, 89.999992, 584.901062, -44.901054);
    add_drug_tray(drugs_tray_amount, 3, 1805.806274, 1321.657714, 1016.358642, 89.999992, 584.934020, -44.934055);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1802.505737, 1321.663330, 1016.358642, 89.999992, 616.605773, 103.394203);
    add_drug_tray(drugs_tray_amount, 1, 1802.505737, 1321.833251, 1016.358642, 89.999992, 616.605773, 103.394203);
    add_drug_tray(drugs_tray_amount, 2, 1802.565795, 1321.663330, 1016.358642, 89.999992, 616.592834, 103.407089);
    add_drug_tray(drugs_tray_amount, 3, 1802.565795, 1321.833251, 1016.358642, 89.999992, 616.605773, 103.394203);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1800.876831, 1321.835693, 1016.358642, 89.999992, 539.901123, 0.098898);
    add_drug_tray(drugs_tray_amount, 1, 1800.876831, 1321.665771, 1016.358642, 89.999992, 539.901123, 0.098898);
    add_drug_tray(drugs_tray_amount, 2, 1800.816772, 1321.835693, 1016.358642, 89.999992, 539.901184, 0.098898);
    add_drug_tray(drugs_tray_amount, 3, 1800.816772, 1321.665771, 1016.358642, 89.999992, 539.901123, 0.098898);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1807.483520, 1317.683959, 1016.358642, 89.999992, 450.000000, -89.999961);
    add_drug_tray(drugs_tray_amount, 1, 1807.483520, 1317.853881, 1016.358642, 89.999992, 450.000000, -89.999969);
    add_drug_tray(drugs_tray_amount, 2, 1807.543579, 1317.683959, 1016.358642, 89.999992, 450.000030, -89.999961);
    add_drug_tray(drugs_tray_amount, 3, 1807.543579, 1317.853881, 1016.358642, 89.999992, 450.000000, -89.999961);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1805.866333, 1317.857666, 1016.358642, 89.999992, 539.934020, 0.065913);
    add_drug_tray(drugs_tray_amount, 1, 1805.866333, 1317.687744, 1016.358642, 89.999992, 539.960449, 0.039517);
    add_drug_tray(drugs_tray_amount, 2, 1805.806274, 1317.857666, 1016.358642, 89.999992, 539.934020, 0.065913);
    add_drug_tray(drugs_tray_amount, 3, 1805.806274, 1317.687744, 1016.358642, 89.999992, 539.934020, 0.065913);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1802.505737, 1317.685913, 1016.358642, 89.999992, 616.592834, 103.407089);
    add_drug_tray(drugs_tray_amount, 1, 1802.505737, 1317.855834, 1016.358642, 89.999992, 616.605773, 103.394203);
    add_drug_tray(drugs_tray_amount, 2, 1802.565795, 1317.685913, 1016.358642, 89.999992, 616.592834, 103.407089);
    add_drug_tray(drugs_tray_amount, 3, 1802.565795, 1317.855834, 1016.358642, 89.999992, 616.592834, 103.407089);
    drugs_tray_amount++;
    
    add_drug_tray(drugs_tray_amount, 0, 1800.874877, 1317.859619, 1016.358642, 89.999992, 450.000030, 89.999984);
    add_drug_tray(drugs_tray_amount, 1, 1800.874877, 1317.689697, 1016.358642, 89.999992, 450.000000, 89.999977);
    add_drug_tray(drugs_tray_amount, 2, 1800.814819, 1317.859619, 1016.358642, 89.999992, 450.000061, 89.999984);
    add_drug_tray(drugs_tray_amount, 3, 1800.814819, 1317.689697, 1016.358642, 89.999992, 450.000030, 89.999984);
    drugs_tray_amount++;
    
    return 1;
}

stock null_drug_tray(id)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "null_drug_tray(id:%i)", id);
    #endif
    if(id == -1) return 1;

    destroy_drug_tray(id, 777);

    gDrugs_Tray[id][gTrayOwner] = INVALID_PLAYER_ID;
    gDrugs_Tray[id][gTrayType] = drugtray_null;
    gDrugs_Tray[id][gTrayTimer] = 0;
    gDrugs_Tray[id][gTrayAmount] = 0;

    UpdateDrugTrayText(id);
    return 1;
}


stock add_drug_tray(id, number, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(id >= MAX_DRUGS_TRAY_AMOUNT) return print("add_drug_tray limit error");

    drugs_tray[id][number][trayX] = x;
    drugs_tray[id][number][trayY] = y;
    drugs_tray[id][number][trayZ] = z;
    drugs_tray[id][number][trayRX] = rx;
    drugs_tray[id][number][trayRY] = ry;
    drugs_tray[id][number][trayRZ] = rz;

    if(number == 0)
    {
        z += 0.5;
        gDrugs_Tray[id][gTrayInfo] = CreateDynamic3DTextLabel("text", -1, x, y, z, DRUG_TRAY_3D_METERS, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, DRUGSHOP_VW, DRUGSHOP_INT);
        
        UpdateDrugTrayText(id);
    }
    
    return 1;
}
stock UpdateDrugTrayText(id)
{
    #if devmode == true
    new string[512];
    #else
    new string[256];
    #endif

    format(string, sizeof(string), ""drp"Стол {F07427}№%i\n\n", id + 1);
    if(gDrugs_Tray[id][gTrayOwner] == INVALID_PLAYER_ID) strcat(string, ""wh"Для взаимодействия\nИспользуйте "drp"L.Alt");
    else
    {
        switch(gDrugs_Tray[id][gTrayType])
        {   
            case drugtray1_takeit:
            {
                new percent_color[16];
                switch(gDrugs_Tray[id][gTrayTimer])
                {
                    case 0..5: percent_color = "cd1c18";
                    case 6..12: percent_color = "F07427";
                    case 13..17: percent_color = "50C878";
                    default: percent_color = "008000";
                }

                format(string, sizeof(string), "%s"wh"Химик: "drp"%s[%i]\n\
                    "wh"Жидкость из кастрюли успешно перелита в поднос!\n\
                    Заберите ее в течении: {%s}%i секунд", 
                    string, Name(gDrugs_Tray[id][gTrayOwner]), gDrugs_Tray[id][gTrayOwner], percent_color, gDrugs_Tray[id][gTrayTimer]);
            }
            case drugtray2_ontable:
            {
                format(string, sizeof(string), "%s"wh"Химик: "drp"%s[%i]\n\
                    "wh"Жидкость в подносе во льду!\n\
                    Разбейте лёд с помощью "drp"L.Alt\n\n\
                    "wh"Оставшееся время: "drp"%s", 
                    string, Name(gDrugs_Tray[id][gTrayOwner]), gDrugs_Tray[id][gTrayOwner], ConvertInGame(gDrugs_Tray[id][gTrayTimer]));
            }
        }
    }
    
    #if devmode == true
    format(string, sizeof(string), "%s\n\n\n"drp"developer:\n"wh"", string);
    switch(gDrugs_Tray[id][gTrayType])
    {
        case drugtray2_ontable:
        {
            format(string, sizeof(string), "%sgTrayTimer = %i\n", string, gDrugs_Tray[id][gTrayTimer]);
            format(string, sizeof(string), "%sgTrayAmount = %i\n", string, gDrugs_Tray[id][gTrayAmount]);
        }
    }
    #endif
    UpdateDynamic3DTextLabelText(gDrugs_Tray[id][gTrayInfo], -1, string);
    return 1;
}

stock drugtray_objectmaterial_setup(tmpobjid, number)
{
    switch(number)
    {
        case 0:
        {
            SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 1, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 2, 18646, "matcolours", "lightblue", 0x00000000);
        }
        case 1:
        {
            SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 1, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 2, 18646, "matcolours", "lightblue", 0x00000000);
        }
        case 2:
        {
            SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 1, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 2, 18646, "matcolours", "lightblue", 0x00000000);
        }
        case 3:
        {
            SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 1, 18646, "matcolours", "lightblue", 0x00000000);
            SetDynamicObjectMaterial(tmpobjid, 2, 18646, "matcolours", "lightblue", 0x00000000);
        }
    }
    return 1;
}
stock create_drug_tray(id, type)
{
    switch(type)
    {
        case 777:
        {
            for(new i = 0; i < 4; i++)
            {
                if(drugs_tray[id][i][trayObjectID] != 0) continue;
                drugs_tray[id][i][trayObjectID] = CreateDynamicObject(19827, drugs_tray[id][i][trayX], drugs_tray[id][i][trayY], drugs_tray[id][i][trayZ], 
                    drugs_tray[id][i][trayRX], drugs_tray[id][i][trayRY], drugs_tray[id][i][trayRZ], -1, 28, -1, 300.00, 300.00); 
                drugtray_objectmaterial_setup(drugs_tray[id][i][trayObjectID], i);
            }
        }
        default:
        {
            if(drugs_tray[id][type][trayObjectID] != 0) return 1;
            drugs_tray[id][type][trayObjectID] = CreateDynamicObject(19827, drugs_tray[id][type][trayX], drugs_tray[id][type][trayY], drugs_tray[id][type][trayZ], 
                drugs_tray[id][type][trayRX], drugs_tray[id][type][trayRY], drugs_tray[id][type][trayRZ], -1, 28, -1, 300.00, 300.00); 
            drugtray_objectmaterial_setup(drugs_tray[id][type][trayObjectID], type);
            
        }
    }
    UpdateDrugTrayText(id);
    return 1;
}
stock destroy_drug_tray(id, type)
{
    switch(type)
    {
        case 777:
        {
            for(new i = 0; i < 4; i++)
            {
                if(drugs_tray[id][i][trayObjectID] != 0)
                {
                    DestroyDynamicObject(drugs_tray[id][i][trayObjectID]);
                    drugs_tray[id][i][trayObjectID] = 0;
                }
            }
        }
        default:
        {
            if(type <= -1) return 2;
            if(type >= 5) return 3;

            if(drugs_tray[id][type][trayObjectID] != 0)
            {
                DestroyDynamicObject(drugs_tray[id][type][trayObjectID]);
                drugs_tray[id][type][trayObjectID] = 0;
            }
        }
    }
    UpdateDrugTrayText(id);
    return 1;
}

stock get_closest_drugs_tray(playerid)
{
    new Float:distance = 1000.0, Float:tempdistance = 0;
    new result = -1;
    for(new i = 0; i < drugs_tray_amount; i++)
    {
        tempdistance = GetPlayerDistanceFromPoint(playerid, drugs_tray[i][0][trayX], drugs_tray[i][0][trayY], drugs_tray[i][0][trayZ]);
        if(tempdistance > 1.0) continue;
        if(gDrugs_Tray[i][gTrayOwner] != INVALID_PLAYER_ID)
        {
            if(gDrugs_Tray[i][gTrayOwner] != playerid) continue;
        }

        if(tempdistance < distance)
        {
            distance = tempdistance;
            result = i;
        }
    }
    return result;
}

stock IsPlayerRentingDrugsTray(playerid)
{
    for(new i = 0; i < drugs_tray_amount; i++)
    {
        if(gDrugs_Tray[i][gTrayOwner] == playerid) return i;
    }
    return -1;
}

stock DrugTray_AfterHit(playerid, id)
{
    ApplyAnimation(playerid, "SWORD", "sword_4", 4.0, 0, 0, 0, 0, 0);

    destroy_drug_tray(id, gDrugs_Tray[id][gTrayAmount]);
    gDrugs_Tray[id][gTrayAmount]++;

    if(gDrugs_Tray[id][gTrayAmount] >= 4) 
    {
        set_drugs_step(playerid, 17);
        SetTimerEx("get_player_drugs",2000,false, "ii", playerid);
        return 1;
    }

    UpdateDrugTrayText(id);
    return 1;
}
function get_player_drugs(playerid)
{
    drugs_remade(playerid);
    drugs_setskin(playerid, 1);
    return 1;
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
stock fridge_init()
{
    fridge_total = 0;

    create_drugs_fridge(1797.7505, 1314.3259, 1016.3287);
    create_drugs_fridge(1797.7502, 1315.3483, 1016.3287);
    create_drugs_fridge(1797.7532, 1316.3370, 1016.3287);
    create_drugs_fridge(1797.7505, 1317.3627, 1016.3287);
    create_drugs_fridge(1797.7539, 1318.2982, 1016.3287);
    create_drugs_fridge(1797.7515, 1319.3713, 1016.3287);
    create_drugs_fridge(1797.7513, 1323.9735, 1016.3287);
    create_drugs_fridge(1797.7502, 1324.9954, 1016.3287);
    create_drugs_fridge(1797.7502, 1325.9480, 1016.3287);
    create_drugs_fridge(1797.7502, 1327.0151, 1016.3287);
    create_drugs_fridge(1797.7502, 1327.9775, 1016.3287);
    create_drugs_fridge(1797.7502, 1329.0005, 1016.3287);

    return 1;
}

stock create_drugs_fridge(Float:x, Float:y, Float:z)
{
    new id = fridge_total;
    if(id >= DRUGS_FRIDGE_AMOUNT) return print("add_drug_tray limit error");
    fridge_total++;

    fridgeinfo[id][f_x] = x;
    fridgeinfo[id][f_y] = y;
    fridgeinfo[id][f_z] = z;

    fridgeinfo[id][f_info] = CreateDynamic3DTextLabel("text", -1, x, y, z, FRIDGE_3D_METERS, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, DRUGSHOP_VW, DRUGSHOP_INT);
    null_fridge(id);
    return 1;
}

stock UpdateFridgeText(id)
{
    #if devmode == true
    new string[512];
    #else
    new string[256];
    #endif

    format(string, sizeof(string), ""drp"Морозильная Камера {F07427}№%i\n\n", id + 1);
    if(fridgeinfo[id][f_owner] == INVALID_PLAYER_ID) strcat(string, ""wh"Для взаимодействия\nИспользуйте "drp"L.Alt");
    else
    {
        switch(fridgeinfo[id][f_type])
        {   
            case fridge_freezeprocess:
            {
                format(string, sizeof(string), "%s"wh"Химик: "drp"%s[%i]\n\
                    "wh"Жидкость в процессе заморозки!\n\
                    Время ожидания: "drp"%s", 
                    string, Name(fridgeinfo[id][f_owner]), fridgeinfo[id][f_owner], ConvertInGame(fridgeinfo[id][f_timer]));
            }
            case fridge_takeit:
            {
                format(string, sizeof(string), "%s"wh"Химик: "drp"%s[%i]\n\
                    "wh"Жидкость успешно заморожена, заберите ее как можно быстрее!\n\
                    У Вас осталось: "drp"%s", 
                    string, Name(fridgeinfo[id][f_owner]), fridgeinfo[id][f_owner], ConvertInGame(fridgeinfo[id][f_timer]));
            }
        }
    }
    
    #if devmode == true
    format(string, sizeof(string), "%s\n\n\n"drp"developer:\n"wh"", string);
    #endif
    UpdateDynamic3DTextLabelText(fridgeinfo[id][f_info], -1, string);
    return 1;
}

stock get_closest_fridge(playerid)
{
    new Float:distance = 1000.0, Float:tempdistance = 0;
    new result = -1;
    for(new i = 0; i < fridge_total; i++)
    {
        tempdistance = GetPlayerDistanceFromPoint(playerid, fridgeinfo[i][f_x], fridgeinfo[i][f_y], fridgeinfo[i][f_z]);
        if(tempdistance > 1.0) continue;
        if(fridgeinfo[i][f_owner] != INVALID_PLAYER_ID)
        {
            if(fridgeinfo[i][f_owner] != playerid) continue;
        }

        if(tempdistance < distance)
        {
            distance = tempdistance;
            result = i;
        }
    }
    return result;
}

stock null_fridge(id)
{
    #if devmode == true
    FSCMTA(COLOR_YELLOW, "null_fridge(id:%i)", id);
    #endif
    if(id == -1) return 1;

    fridgeinfo[id][f_owner] = INVALID_PLAYER_ID;
    fridgeinfo[id][f_type] = fridge_null;
    fridgeinfo[id][f_timer] = 0;

    UpdateFridgeText(id);
    return 1;
}

stock IsPlayerRentingFridge(playerid)
{
    for(new i = 0; i < fridge_total; i++)
    {
        if(fridgeinfo[i][f_owner] == playerid) return i;
    }
    return -1;
}