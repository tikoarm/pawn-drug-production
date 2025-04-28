CMD:drugs_help(playerid)
{
    SendTipp(playerid, "DEVELOPER MODE: /set_auto_drugs [amount] /create_auto_drugs /get_drugs");
    return 1;
}
CMD:set_auto_drugs(playerid, params[])
{
    if(sscanf(params, "d", params[0])) return error(playerid, "Испольуй: /set_auto_drugs [amount]");
    if(get_player_drug_vehicle(playerid) == INVALID_VEHICLE_ID) return error(playerid, "Сядь в машину!!");

    DrugSystemInfo[get_player_drug_vehicle(playerid)][dsLoadedAmount] = params[0];
    SendTipp(playerid, "Готово!");
    UpdateDrugsAutoMarker(get_player_drug_vehicle(playerid));
    return 1;
}

CMD:create_auto_drugs(playerid)
{
    new Float:x, Float:y, Float:z, hours = 10;
    GetPlayerPos(playerid, x, y, z);
    new vehicleid = AddStaticVehicleEx(DRUGS_AUTO_MODEL, x, y, z, 0.0, 0, 0, -1);
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
    SendTipp(playerid, "Готово!");
    return 1;
}

CMD:get_drugs(playerid)
{
    DrugsHolding[playerid] += get_player_drugs_max(playerid);
    Tipp(playerid, "Выдано %i", get_player_drugs_max(playerid));
    return 1;
}

CMD:1(playerid)
{
    if(!get_drugs_onwork(playerid))
    {
        if(!DrugsHolding[playerid])
        {
            DrugsHolding[playerid] += get_player_drugs_max(playerid);
            Tipp(playerid, "Выдано %i", get_player_drugs_max(playerid));
        }
    }
    
    drugs_setskin(playerid);
    if(get_drugs_onwork(playerid))
    {
        SCM(playerid, -1, " ");

        Streamer_Update(playerid);
        ApplyAnimation(playerid,"CARRY","crry_prtial",4.1,0,1,1,1,1);
        SetPlayerAttachedObject(playerid, 1, 19809, 5, 0.133999, 0.063999, 0.143000, -81.299606, 3.399996, 14.000029, 1.000000, 1.000000, 1.000000, 0x0, 0x0);
        SetPlayerAttachedObject(playerid, 2, 19827, 6, 0.101000, 0.115999, -0.195000, -18.099971, -11.500021, 0.800001, 1.536004, 1.886025, 1.925009, 0xFF00C0FF, 0x0);

        set_drugs_step(playerid, 15);
        send_drugs_help_message(playerid);
    }
    return 1;
}
