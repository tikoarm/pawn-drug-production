CMD:test(playerid)
{
    SetPlayerSpecialAction (playerid, SPECIAL_ACTION_CARRY);
    SetPlayerAttachedObject(playerid, 1, 19585, 4, 0.272998, -0.317999, -0.054000, 19.099998, -98.200012, 86.100013, 0.851998, 0.864998, 0.726999);
    SetPlayerAttachedObject(playerid, 2, 19580, 4, 0.290997, -0.389998, 0.121999, 3.799999, 80.499984, 2.899996, 0.585997, 0.561998, 0.594000);
    return 1;
}

stock drugs_remade(playerid)
{ // Самая главная функция системы
    if(PlayerInfo[playerid][pJob] != 4) return error(playerid, "Ты не наркодиллер.");
    if(!IsAGang(playerid)) return error(playerid, "Ты не состоишь в банде/мафии.");
    if(!DrugsHolding[playerid]) return error(playerid, "Препараты не закуплены.");

    new payout = (1) * (DrugsHolding[playerid]);
    format(stringer, sizeof(stringer), "Ты получил%s %d грамм наркотиков из %d препаратов.", Sex(playerid) == 1 ? "" : "a", payout, DrugsHolding[playerid]);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, stringer);

    AddFracQuest(playerid, 1, 2, payout);
    AddItem(playerid, I_DRUGS, payout);
    DrugsHolding[playerid] = 0;
	DeletePVar(playerid,"TextSnowCvest15Narko");

    PlayerInfo[playerid][pDrugsSkill]++;
    UpdatePlayerData(playerid, "DrugsSkill", PlayerInfo[playerid][pDrugsSkill]);

    /* РЕПУТАЦИЯ БАНД И МАФИЙ */
	if(PlayerInfo[playerid][pLeader] == 5 || PlayerInfo[playerid][pMember] == 5) { RLCN += 2; }
	if(PlayerInfo[playerid][pLeader] == 6 || PlayerInfo[playerid][pMember] == 6) { RYakuza += 2; }
	if(PlayerInfo[playerid][pLeader] == 7 || PlayerInfo[playerid][pMember] == 7) { RTriada += 2; }
	if(PlayerInfo[playerid][pLeader] == 10 || PlayerInfo[playerid][pMember] == 10) { RBallas += 2; }
	if(PlayerInfo[playerid][pLeader] == 11 || PlayerInfo[playerid][pMember] == 11) { RGrove += 2; }
	if(PlayerInfo[playerid][pLeader] == 12 || PlayerInfo[playerid][pMember] == 12) { RVagos += 2; }
	if(PlayerInfo[playerid][pLeader] == 13 || PlayerInfo[playerid][pMember] == 13) { RCoronos += 2; }
	if(PlayerInfo[playerid][pLeader] == 14 || PlayerInfo[playerid][pMember] == 14) { RRifa += 2; }
	if(PlayerInfo[playerid][pLeader] == 15 || PlayerInfo[playerid][pMember] == 15) { RRM += 2; }
	if(PlayerInfo[playerid][pLeader] == 17 || PlayerInfo[playerid][pMember] == 17) { RSTR += 2; }
	if(PlayerInfo[playerid][pLeader] == 18 || PlayerInfo[playerid][pMember] == 18) { RLVSTR += 2; }
	if(PlayerInfo[playerid][pLeader] == 20 || PlayerInfo[playerid][pMember] == 20) { RBaikers += 2; }
	if(PlayerInfo[playerid][pLeader] == 21 || PlayerInfo[playerid][pMember] == 21) { LSConvers += 2; }
	SaveRep();

    if(PlayerInfo[playerid][pDrugsSkill] == 50) { SendClientMessage(playerid, COLOR_YELLOW, "Твой навык наркодиллера теперь: 2, теперь ты можешь закупать по 60 препаратов."); }
	else if(PlayerInfo[playerid][pDrugsSkill] == 100) { SendClientMessage(playerid, COLOR_YELLOW, "Твой навык наркодиллера теперь: 3, теперь ты можешь закупать по 120 препаратов."); }
	else if(PlayerInfo[playerid][pDrugsSkill] == 200) { SendClientMessage(playerid, COLOR_YELLOW, "Твой навык наркодиллера теперь: 4, теперь ты можешь закупать по 160 препаратов."); }
	else if(PlayerInfo[playerid][pDrugsSkill] == 400) { SendClientMessage(playerid, COLOR_YELLOW, "Твой навык наркодиллера теперь: 5, теперь ты можешь закупать по 200 препаратов."); }

    if(Genry[playerid] == 15) {if(PlayerInfo[playerid][pCvest15] < 1) {if(PlayerInfo[playerid][pDrugsSkill] == 1) {SendClientMessage(playerid,COLOR_LIGHTGREEN,"Наркотики получены из препаратов! Осталось доставить 9 шт. до завершения задания."); ShowPlayerDialogEx(playerid,0,DIALOG_STYLE_MSGBOX,"{3399CC}Босс","\n\n{FFFFFF}Хорошо! Тебе ещё 9 раз нужно перевезти и сделать из препаратов наркотики.\n\n","Ок","");} } }
	if(Genry[playerid] == 15) {if(PlayerInfo[playerid][pCvest15] < 1) {if(PlayerInfo[playerid][pDrugsSkill] == 5) {SendClientMessage(playerid,COLOR_LIGHTGREEN,"Наркотики получены из препаратов! Осталось доставить 5 шт. до завершения задания."); } } }
	if(Genry[playerid] == 15) {if(PlayerInfo[playerid][pCvest15] < 1) {if(PlayerInfo[playerid][pDrugsSkill] == 7) {SendClientMessage(playerid,COLOR_LIGHTGREEN,"Наркотики получены из препаратов! Осталось доставить 3 шт. до завершения задания."); ShowPlayerDialogEx(playerid,0,DIALOG_STYLE_MSGBOX,"{3399CC}Босс","\n\n{FFFFFF}Хорошо! Ты уже почти у цели, осталось 3 раза.\n\n","Ок","");} } }
		
    if(PlayerInfo[playerid][pCvest15] < 1 && Genry[playerid] == 15)
	{
		if(PlayerInfo[playerid][pDrugsSkill] == 10)
		{
			ShowPlayerDialogEx(playerid,0,DIALOG_STYLE_MSGBOX,"{3399CC}Босс","\n\n{FFFFFF}Хорошо! Задание успешно выполнено. Вот твоя награда!\n\n","Ок","");
			PlayerInfo[playerid][pCvest15] = 1;
			Genry[playerid] = 0;

			PlayerInfo[playerid][pExp] += 1;
			GiveMoney(playerid, 8000);
			GameTextForPlayer(playerid,"~b~Mission complete~n~~b~+~y~1 ~g~exp ~b~+~y~8000~g~$",5000,6);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			SaveQuest(playerid);
			LevelUpdate(playerid);
		}
    }
    return 1;
}

/* */
/* */
/* */

stock drugs_abo_valid(playerid)
{
    new amount = CountItem(playerid, I_DRUGS_ABO);
    if(!amount) return 0;
    if(amount > unixtime) return 1;
    TakeItem(playerid, I_DRUGS_ABO, amount);
    return 0;
}
stock DrugsAboToBuy(playerid)
{
    if(drugs_abo_valid(playerid)) return error(playerid, "У Вас уже куплен абонемент в спорт зал!");
    ShowPlayerDialogEx(playerid, 1244, DIALOG_STYLE_MSGBOX, ""wh"Фитнес", ""wh"\
        Мы слышали, что ты хочешь попасть в наш Фитнес-клуб?))\n\
        Готовы продать тебе абонемент на 24 часа, всего за 25000$\n\
        Согласен?\
    ", "Да", "Нет");
    return 1;
}

/* */
/* */
/* */

stock RentDrugVehicle(playerid, hours)
{
    if(get_player_drug_vehicle(playerid) != INVALID_VEHICLE_ID) return 1;

    new price;
    if(hours == 1) price = 5000;
    else if(hours == 2) price = 10000;
    else if(hours == 5) price = 23000;

    if(PlayerInfo[playerid][pMoney] < price) return error(playerid, "У Вас недостаточно денег!");
    GiveMoney(playerid, -price);

    new Float:xyz_auto[3][4] = {
        {2795.3508,-2440.7102,13.7132,89.3007},
        {2795.1594,-2436.7986,13.7123,91.6269},
        {2794.9543,-2432.4631,13.7338,90.5806}
    };
    new rand = random(3);

    new vehicleid = AddStaticVehicleEx(DRUGS_AUTO_MODEL, xyz_auto[rand][0], xyz_auto[rand][1], xyz_auto[rand][2], xyz_auto[rand][3], 0, 0, -1);
	PutPlayerInVehicle(playerid, vehicleid, 0);
	DestroyObject(neon[vehicleid][0]); 
    DestroyObject(neon[vehicleid][1]);
    neon[vehicleid][0] = 0; 
    neon[vehicleid][1] = 0;
    EngineCar[vehicleid] = 0;
    vehicle_drug_vars_tonull(vehicleid);

    set_player_drug_vehicle(playerid, vehicleid);
    set_player_drug_vehicle_unix(playerid, (unixtime + hours * 3600));
    DrugSystemInfo[vehicleid][dsOwner] = playerid;
    DrugSystemInfo[vehicleid][dsDrugAuto] = true;
    return 1;
}
stock StopRentDrugVehicle(playerid)
{
    if(get_player_drug_vehicle(playerid) == INVALID_VEHICLE_ID) return 1;
    new vehicleid = get_player_drug_vehicle(playerid);
    player_drug_vars_tonull(playerid);

    DestroyVehicle(vehicleid);
    DestroyDrugsAutoMarker(vehicleid);
    vehicle_drug_vars_tonull(vehicleid);
    return 1;
}

stock Drugs_OneSecondTimer(playerid)
{
    if(get_player_drug_vehicle(playerid) != INVALID_PLAYER_ID)
    {
        if(get_player_drug_vehicle_unix(playerid) < unixtime) StopRentDrugVehicle(playerid);
    }
    return 1;
}

stock CreateDrugsAutoMarker(vehicleid)
{
    if(DrugSystemInfo[vehicleid][dsCreated] == 1) return 0;
    new Float:X,Float:Y,Float:Z;
    GetCoordBootVehicle(vehicleid, X, Y, Z);

    DrugSystemInfo[vehicleid][dsPosX] = X;
    DrugSystemInfo[vehicleid][dsPosY] = Y;
    DrugSystemInfo[vehicleid][dsPosZ] = Z;
    DrugSystemInfo[vehicleid][dsLoadPickup] = CreateDynamicPickup(19135, 1, X, Y, Z, 0, 0, DrugSystemInfo[vehicleid][dsOwner]);
    DrugSystemInfo[vehicleid][dsText] = CreateDynamic3DTextLabel("text", -1, X, Y, Z, 14.0);
    DrugSystemInfo[vehicleid][dsCreated] = 1;
    UpdateDrugsAutoMarker(vehicleid);
    return 1;
}
stock UpdateDrugsAutoMarker(vehicleid)
{
    if(DrugSystemInfo[vehicleid][dsCreated] == 0) return 0;

    new string[256];
    format(string, sizeof(string), "{F4CA16}Для разгрузки или выгрузки\nиспользуйте {EB4C42}L.Alt\n\n{F4CA16}Степень загруженности: [ {318CE7}%i / %i {F4CA16}]", 
        DrugSystemInfo[vehicleid][dsLoadedAmount], get_player_drugs_max(DrugSystemInfo[vehicleid][dsOwner]));
    UpdateDynamic3DTextLabelText(DrugSystemInfo[vehicleid][dsText], -1, string);
    return 1;
}
stock DestroyDrugsAutoMarker(vehicleid)
{
    if(DrugSystemInfo[vehicleid][dsCreated] == 0) return 0;

    DestroyDynamicPickup(DrugSystemInfo[vehicleid][dsLoadPickup]);
    DestroyDynamic3DTextLabel(DrugSystemInfo[vehicleid][dsText]);
    DrugSystemInfo[vehicleid][dsCreated] = 0;
    DrugSystemInfo[vehicleid][dsPosX] = 0.0;
    DrugSystemInfo[vehicleid][dsPosY] = 0.0;
    DrugSystemInfo[vehicleid][dsPosZ] = 0.0;
    return 1;
}

stock Float:DistanceBetweenXYZ(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

stock VehicleAutoPickXYZ_Check(vehicleid)
{
    new Float:PickupX, Float:PickupY, Float:PickupZ;
    GetCoordBootVehicle(vehicleid, PickupX, PickupY, PickupZ);
    if(DistanceBetweenXYZ(DrugSystemInfo[vehicleid][dsPosX], DrugSystemInfo[vehicleid][dsPosY], DrugSystemInfo[vehicleid][dsPosZ], PickupX, PickupY, PickupZ) > 1.0)
    {
        DestroyDrugsAutoMarker(vehicleid);
        CreateDrugsAutoMarker(vehicleid);
        return 1;
    }

    return 0;
}

stock KeyWalk_Drugs(playerid)
{
    if(get_drugs_onwork(playerid))
    {
        if(drugs_abo_valid(playerid))
        {
            staticdrugs_alt(playerid);
        }
    }


    new vehicleid = get_player_drug_vehicle(playerid);
    if(vehicleid == INVALID_VEHICLE_ID) return 1;
    if(DrugSystemInfo[vehicleid][dsCreated] == 0) return 1;

    if(IsPlayerInRangeOfPoint(playerid, 2.0, DRUGS_RAZGRUZKA_XYZ))
    {
        if(!get_player_holding_drugs(playerid)) return error(playerid, "У Вас недостаточно препаратов!");
        DrugsHolding[playerid] += get_player_holding_drugs(playerid);
        Tipp(playerid, "Вы успешно выгрузили %i препараторов! Всего: %i препаратов", get_player_holding_drugs(playerid), DrugsHolding[playerid]);
        set_player_holding_drugs(playerid, 0);

        RemovePlayerAttachedObject(playerid,1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 1;
    }

    if(!IsPlayerInRangeOfPoint(playerid, 0.5, DrugSystemInfo[vehicleid][dsPosX], DrugSystemInfo[vehicleid][dsPosY], DrugSystemInfo[vehicleid][dsPosZ])) return 1;
    if(VehicleAutoPickXYZ_Check(vehicleid) == 1) return 0;

    new in_auto_drugs = DrugSystemInfo[vehicleid][dsLoadedAmount];

    if(get_player_holding_drugs(playerid))
    {
        DrugSystemInfo[vehicleid][dsLoadedAmount] += get_player_holding_drugs(playerid);
        Tipp(playerid, "Вы успешно положили %i препараторов в автомобиль!", get_player_holding_drugs(playerid));
        set_player_holding_drugs(playerid, 0);
        UpdateDrugsAutoMarker(vehicleid);
        
        RemovePlayerAttachedObject(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        return 1;
    }

    if(in_auto_drugs)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 15.0, DRUGS_RAZGRUZKA_XYZ)) return error(playerid, "Выгрузка возможна только в точке разгрузки!");

        new amount = get_holdingdrugs_amount(playerid);
        if(amount > DrugSystemInfo[vehicleid][dsLoadedAmount]) amount = DrugSystemInfo[vehicleid][dsLoadedAmount];
        Tipp(playerid, "Вы успешно взяли %i препараторов, отнесите их на точку отгрузки!", amount);
        set_player_holding_drugs(playerid, amount);
        DrugSystemInfo[vehicleid][dsLoadedAmount] -= amount;
        UpdateDrugsAutoMarker(vehicleid);
        
        new drug_models[6] = {1575, 1580, 1576, 1577, 1578, 1579};
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, 1, drug_models[random(6)], 1,0.11,0.36,0.0,0.0,90.0);
    } else return error(playerid, "В перевозчике ничего нет!");
    return 1;
}
public OnGameModeInit()
{
    cooking_ranges_init();
    drug_tray_init();
    fridge_init();
    
    null_pan(0, 1);
    null_pan(1, 1);

    new pickupid = CreateDynamicPickup(2485, 23, DRUGSAUTO_RENT_XYZ, 0);
    set_drug_vehicle_pickupid(pickupid);
    CreateDynamic3DTextLabel("{20B2AA}Аренда Грузовика", -1, DRUGSAUTO_RENT_XYZ, 14.0);

    pickupid = CreateDynamicPickup(1239, 23, DRUGS_RAZGRUZKA_XYZ, 0);
    set_drugs_razgruzka_pickup(pickupid);
    CreateDynamic3DTextLabel("{20B2AA}Место выгрузки пакетов\nНажмите "wh"L.Alt", -1, DRUGS_RAZGRUZKA_XYZ, 14.0);

    CreateActor(5, 2179.8232, -1656.1021, 15.0793, 295.8163);

    TochkaVarki[0] = CreateDynamic3DTextLabel("-", -1, 1805.7031,1334.7668,1017.5731, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DRUGSHOP_VW, DRUGSHOP_INT);
    TochkaVarki[1] = CreateDynamic3DTextLabel("-", -1, 1814.4087,1334.1793,1017.5731, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DRUGSHOP_VW, DRUGSHOP_INT);
    UpdateDynamicVarkaText(0);
    UpdateDynamicVarkaText(1);
    

    #if defined drugs_OnGameModeInit
		drugs_OnGameModeInit();
	#endif
    return 1;
}

stock DrugPickupTaken(playerid, number)
{
    if(!get_drugs_onwork(playerid)) return 0;

    #if devmode == true
    FSCMTA(COLOR_YELLOW, "DrugPickupTaken(playerid:%i, number:%i)", playerid, number);
    #endif

    switch(number)
    {
        case 8:
        {
            if(get_drugs_step(playerid) != 0) return 1;
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		    SetPlayerAttachedObject(playerid, 1, 1578, 1,0.11,0.36,0.0,0.0,90.0);
            set_drugs_step(playerid, 1);
            send_drugs_help_message(playerid);
        }
        case 10, 11:
        {
            #if devmode == true
            FSCMTA(COLOR_YELLOW, "1 | get_drugs_tableid(playerid:%i) = %i", playerid, get_drugs_tableid(playerid));
            #endif

            if(get_drugs_step(playerid) != 1) return 1;
            if(number == 10) set_drugs_tableid(playerid, 1);
            else if(number == 11) set_drugs_tableid(playerid, 2);

            RemovePlayerAttachedObject(playerid, 1);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

            set_drugs_step(playerid, 2);
            send_drugs_help_message(playerid);

            #if devmode == true
            FSCMTA(COLOR_YELLOW, "2 | get_drugs_tableid(playerid:%i) = %i", playerid, get_drugs_tableid(playerid));
            #endif
        }
        case 9:
        {
            if(get_drugs_step(playerid) != 2) return 1;
	        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		    SetPlayerAttachedObject(playerid, 1, 1575, 1,0.11,0.36,0.0,0.0,90.0);
            set_drugs_step(playerid, 3);
            send_drugs_help_message(playerid);
        }
        case 12, 13:
        {
            #if devmode == true
            FSCMTA(COLOR_YELLOW, "get_drugs_tableid(playerid:%i) = %i | number = %i", playerid, get_drugs_tableid(playerid), number);
            #endif
            if(get_drugs_step(playerid) != 3) return 1;

            switch(number)
            {
                case 12: if(get_drugs_tableid(playerid) != 1) return error(playerid, "Вы начали работу за другим столом!");
                case 13: if(get_drugs_tableid(playerid) != 2) return error(playerid, "Вы начали работу за другим столом!");
            }

            RemovePlayerAttachedObject(playerid, 1);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            
            set_drugs_step(playerid, 4);
            send_drugs_help_message(playerid);
        }
        case 14, 15:
        {
            if(get_drugs_step(playerid) == 4) return player_pressed_alt_on_pan(playerid, number);
            else if(get_drugs_step(playerid) == 6)
            {

                switch(number)
                {
                    case 14: if(get_drugs_tableid(playerid) != 1) return error(playerid, "Вы начали работу за другим столом!");
                    case 15: if(get_drugs_tableid(playerid) != 2) return error(playerid, "Вы начали работу за другим столом!");
                }
                SetPlayerSpecialAction (playerid, SPECIAL_ACTION_CARRY);

		        RemovePlayerAttachedObject(playerid, 1);
                RemovePlayerAttachedObject(playerid, 2);
                SetPlayerAttachedObject(playerid, 1, 19585, 4, 0.272998, -0.317999, -0.054000, 19.099998, -98.200012, 86.100013, 0.851998, 0.864998, 0.726999);
                SetPlayerAttachedObject(playerid, 2, 19580, 4, 0.290997, -0.389998, 0.121999, 3.799999, 80.499984, 2.899996, 0.585997, 0.561998, 0.594000);

                null_pan(IsPlayerRentingDrugsPan(playerid));

                Streamer_Update(playerid);
                set_drugs_step(playerid, 7);
                send_drugs_help_message(playerid);
                return 1;
            }
            else return 1;
        }
    }
    return 1;
}

#include ../modules/systems/drugs/hooks

/* */
stock get_drugs_level(playerid)
{
    new level = PlayerInfo[playerid][pDrugsSkill];
    
    if(level >= 0 && level <= 49) return 1;
	else if(level >= 50 && level <= 99) return 2;
	else if(level >= 100 && level <= 199) return 3;
	else if(level >= 200 && level <= 399) return 4;
	else if(level >= 400) return 5;
    return 1;
}
stock get_holdingdrugs_amount(playerid)
{
    new amount = 1;
    switch(get_drugs_level(playerid))
    {
        case 1: amount = 3;
        case 2: amount = 5;
        case 3: amount = 8;
        case 4: amount = 10;
        case 5: amount = 20;
    }
    return amount;
}
stock get_player_drugs_max(playerid)
{
    new level = get_drugs_level(playerid);

    if(level == 1) return 30;
    else if(level == 2) return 60;
    else if(level == 3) return 120;
    else if(level == 4) return 160;
    else if(level == 5) return 200;
    return 30;
}
stock get_means_pickup(playerid)
{
    if(PlayerInfo[playerid][pJob] != 4) return error(playerid, "Ты не наркодиллер.");
    if(!IsAGang(playerid)) return error(playerid, "Ты не состоишь в банде/мафии.");
    if(!PlayerToPoint(3.0,playerid, 2823.4001, -2464.8486, 12.0960)) return error(playerid, "Ты не у холдинга с наркотиками.");
    if(get_player_holding_drugs(playerid) >= 1) return error(playerid, "Сначала переработай прошлую партию препаратов.");
    if(get_player_drug_vehicle(playerid) == INVALID_VEHICLE_ID) return error(playerid, "Для перевозки препаратов нужно арендовать грузовик!");

    new add_amount = get_holdingdrugs_amount(playerid);

    new vehicleid = get_player_drug_vehicle(playerid);
    if(DrugSystemInfo[vehicleid][dsLoadedAmount] >= get_player_drugs_max(playerid)) return error(playerid, "Ваша машина полностью загружена!");
    if(DrugSystemInfo[vehicleid][dsLoadedAmount] + get_holdingdrugs_amount(playerid) > get_player_drugs_max(playerid))
    {
        new maximum = get_player_drugs_max(playerid);
        new now_amount = DrugSystemInfo[vehicleid][dsLoadedAmount];
        
        add_amount = maximum - now_amount;
    }

    new string[512];
    format(string, sizeof(string), "\n\
        {FFFFFF}Вы собираетесь приобрести: {318CE7}%i{FFFFFF} препаратов\n\
        {FFFFFF}Общая сумма покупки: {318CE7}%i $\n\
        {FFFFFF}Вы подтверждаете действие?\
    ", add_amount, ONE_DRUG_PRICE * add_amount);
    ShowPlayerDialogEx(playerid, 5114, DIALOG_STYLE_MSGBOX, "{FFFFFF}Покупка препаратов", string, "Да", "Нет");
    return 1;
}
stock get_means(playerid)
{
    if(PlayerInfo[playerid][pJob] != 4) return error(playerid, "Ты не наркодиллер.");
    if(!IsAGang(playerid)) return error(playerid, "Ты не состоишь в банде/мафии.");
    if(!PlayerToPoint(3.0,playerid, 2823.4001, -2464.8486, 12.0960)) return error(playerid, "Ты не у холдинга с наркотиками.");
    if(get_player_holding_drugs(playerid) >= 1) return error(playerid, "Сначала переработай прошлую партию препаратов.");
    if(get_player_drug_vehicle(playerid) == INVALID_VEHICLE_ID) return error(playerid, "Для перевозки препаратов нужно арендовать грузовик!");

    new amount = get_holdingdrugs_amount(playerid);
    if(YNarko < amount) return error(playerid, "Недостаточно препаратов.");
    
    new price = amount * ONE_DRUG_PRICE;
    if(price > PlayerInfo[playerid][pMoney]) return error(playerid, "У тебя нет столько денег.");

	if(PlayerInfo[playerid][pOtkat] >= 1) return SFM(playerid,COLOR_WHITE,"Анти-флуд система: До закупки следующей партии препаратов подожди {e3be88}%s.", ConvertInGame(PlayerInfo[playerid][pOtkat]));

    new vehicleid = get_player_drug_vehicle(playerid);
    if(DrugSystemInfo[vehicleid][dsLoadedAmount] >= get_player_drugs_max(playerid)) return error(playerid, "Ваша машина полностью загружена!");
    if(DrugSystemInfo[vehicleid][dsLoadedAmount] + get_holdingdrugs_amount(playerid) > get_player_drugs_max(playerid))
    {
        new maximum = get_player_drugs_max(playerid);
        new now_amount = DrugSystemInfo[vehicleid][dsLoadedAmount];
        
        amount = maximum - now_amount;
    }
	
    format(stringer, sizeof(stringer), "Ты закупил%s %d препаратов за $%d. Положи их в автомобиль",Sex(playerid) == 1 ? "" : "a",  amount, price);
   	SendClientMessage(playerid, COLOR_LIGHTBLUE, stringer);

    GiveMoney(playerid, -price);
   	set_player_holding_drugs(playerid, amount);
   	YNarko -= amount;
   	PlayerInfo[playerid][pOtkat] = OTKAT_ZAGRUZKA_SEC;
   	if(PlayerInfo[playerid][pCvest15] < 1 && Genry[playerid] == 15) { SetPlayerCheckpoint(playerid, 2178.3088,-1660.2241,14.9781,2.0), SetPVarInt(playerid,"gps_on",1); if(!GetPVarInt(playerid, "TextSnowCvest15Narko")) ShowPlayerDialogEx(playerid,0,DIALOG_STYLE_MSGBOX,"{3399CC}Босс","\n\n{FFFFFF}Препараты успешно куплены, теперь загрузи их в грузовик. После того как загрузишь, садись в грузовик и езжай обратно, выгрузи их. Я отметил тебе красной меткой на карте!\n\n","Ок","");}
	SetPVarInt(playerid, "TextSnowCvest15Narko", 1);
    new drug_models[6] = {1575, 1580, 1576, 1577, 1578, 1579};
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
	SetPlayerAttachedObject(playerid, 1, drug_models[random(6)], 1,0.11,0.36,0.0,0.0,90.0);
    return 1;
}
/* */

/* */
/* */
/* */

stock drugs_setskin(playerid, ignore = 0)
{
    if(!ignore)
    {
        if(get_drugs_antiflood(playerid) > unixtime) return Tipp(playerid, "Не флудите! Попробуйте через %s", ConvertInGame(get_drugs_antiflood(playerid) - unixtime));
    }

    if(!get_drugs_onwork(playerid))
    {
        if(!drugs_abo_valid(playerid)) return error(playerid, "У Вас не куплен абонемент в спортивный зал!");
        if(!DrugsHolding[playerid]) return error(playerid, "Вы не разгрузили пакеты!");

        SetPlayerSkinEx(playerid, DRUGSHOP_SKINID);
        SendTipp(playerid, "Вы успешно переоделись в форму наркодиллера.");
        SendTipp(playerid, "Если вы уволитесь, весь ваш прогресс будет сброшен!");

        set_drugs_onwork(playerid, 1);
        set_drugs_step(playerid, 0);
        set_drugs_tableid(playerid, 0);

        send_drugs_help_message(playerid);

        #if devmode == true
        SCM(playerid, -1, " ");
        SendTipp(playerid, "На данной работе активирован режим разработчика.");
        SendTipp(playerid, "Все ваши действия сопровождаются логами, а также все задержки были изменены.");
        #endif
    }
    else
    {
        null_pan(IsPlayerRentingDrugsPan(playerid));
        null_cooking_range(IsPlayerRentingCook(playerid));
        null_drug_tray(IsPlayerRentingDrugsTray(playerid));
	    null_fridge(IsPlayerRentingFridge(playerid));

        SetPlayerSkinEx(playerid, PlayerInfo[playerid][pChar]);
        SendTipp(playerid, "Вы успешно переоделись в свою форму");

        set_drugs_onwork(playerid, 0);
    }

    set_drugs_antiflood(playerid, unixtime + CHANGE_DRUGSKIN_KD);
    return 1;
}

stock send_drugs_help_message(playerid)
{
    if(!get_drugs_onwork(playerid)) return 1;
    if(!drugs_abo_valid(playerid)) return error(playerid, "У Вас не куплен абонемент в спортивный зал!");

    switch(get_drugs_step(playerid))
    {
        case 0: SendTipp(playerid, "Вам необходимо взять в руки зеленый пакет в руки!");
        case 1: SendTipp(playerid, "Вам необходимо отнести зеленый пакет к любой точке приготовления!");
        case 2: SendTipp(playerid, "Вам необходимо взять в руки белый пакет в руки!");
        case 3: SendTipp(playerid, "Вам необходимо отнести белый пакет к любой точке приготовления!");
        case 4: SendTipp(playerid, "Подойдите к точке наполнения и нажмите L.Alt");
        case 5: SendTipp(playerid, "Ожидайте, пока смесь приготовится");
        case 6: SendTipp(playerid, "Заберите смесь как можно быстрее!");
        case 7: SendTipp(playerid, "Отнесите кастрюлю на плиту для варки!");
        case 8: SendTipp(playerid, "Дождитесь пока вязкость вещества станет 100!");
        case 9: SendTipp(playerid, "Заберите кастрюлю с варочной поверхности!");
        case 10: SendTipp(playerid, "Вылейте вещество из кастрюли на поднос");
        case 11: SendTipp(playerid, "Заберите поднос как можно скорее!");
        case 12: SendTipp(playerid, "Отнесите поднос в морозильную камеру!");
        case 13: SendTipp(playerid, "Ожидайте, пока жидкость замерзает...");
        case 14: SendTipp(playerid, "Заберите поднос из морозильной камеры");
        case 15: SendTipp(playerid, "Разместите поднос на столе и разбейте лёд!");
        case 16: SendTipp(playerid, "Разбейте весь лёд с помощью кнопки L.Alt!");
    }
    return 1;
}