#define devmode                     false
#define COOKING_RANGE_3D_METERS     1.5
#define DRUG_TRAY_3D_METERS         1.5
#define FRIDGE_3D_METERS            1.5
#define VYAZKOST_V_SECUNDU          5 // По стандарту сколько вязкости добавляется на втором этапе в секунду

/* */
/* */
/* */

#define DRUGS_AUTO_MODEL    413
#define DRUGSAUTO_RENT_XYZ  2805.1460, -2428.6077, 13.6294
#define ONE_DRUG_PRICE      50
#define OTKAT_ZAGRUZKA_SEC  3

#define DRUGS_RAZGRUZKA_XYZ  2178.3088, -1660.2241, 14.9781

#define DIALOG_VEHICLE_RENT ShowPlayerDialogEx(playerid, 3153, DIALOG_STYLE_TABLIST, "{FFFFFF}Аренда Грузовика", "{FFFFFF}На сколько часов Вы желаете арендовать грузовик?\t>\n1 час\t5000$\n2 часа\t10000$\n5 часов\t23000$", "Выбрать", "Закрыть")

enum DrugsSystemVehicleInfo
{
    dsLoadPickup,
    dsOwner,
    Text3D:dsText,
    dsCreated,
    Float:dsPosX,
    Float:dsPosY,
    Float:dsPosZ,
    dsLoadedAmount,
    bool:dsDrugAuto
};
new DrugSystemInfo[MAX_VEHICLES][DrugsSystemVehicleInfo];


/* */
/* */
/* */

#define DRUGSHOP_INT    28
#define DRUGSHOP_VW     1

#define DRUGSHOP_SETSKINXYZ        1809.8529, 1308.3987, 1016.3267
#define DRUGSHOP_SKINID            144

new Text3D:TochkaVarki[2];

#if devmode == true
///////////////////////////////////////////////////////////////////////////////////////////////////
    #define SECONDS_FOR_PAN_TO_BEREADY  15
    #define SECONDS_FOR_PAN_TO_TAKE     20
    #define CHANGE_DRUGSKIN_KD          2

    #define DRUGS_MAXIMAL_VYAZKA        100
    #define DRUGS_DELETE_VYAZKA         125

    #define FRIDGE_FREEZEPROCESS_SEC    25
    #define FRIDGE_TAKEIT_SEC           30

    #define DRUGTRAY_2_WORKTIME_SEC     3 * 60
    #define DRUGTRAY_2_KD_SEC           3
///////////////////////////////////////////////////////////////////////////////////////////////////
#else
///////////////////////////////////////////////////////////////////////////////////////////////////
    #define SECONDS_FOR_PAN_TO_BEREADY  30
    #define SECONDS_FOR_PAN_TO_TAKE     10
    #define CHANGE_DRUGSKIN_KD          60

    #define DRUGS_MAXIMAL_VYAZKA        100
    #define DRUGS_DELETE_VYAZKA         125

    #define FRIDGE_FREEZEPROCESS_SEC    1 * 60
    #define FRIDGE_TAKEIT_SEC           60

    #define DRUGTRAY_2_WORKTIME_SEC     5 * 60
    #define DRUGTRAY_2_KD_SEC           3
///////////////////////////////////////////////////////////////////////////////////////////////////
#endif