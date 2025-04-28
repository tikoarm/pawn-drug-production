static drug_vehicle_rent_player[MAX_PLAYERS];
stock get_player_drug_vehicle(playerid) return drug_vehicle_rent_player[playerid];
stock set_player_drug_vehicle(playerid, value) {
    drug_vehicle_rent_player[playerid] = value;
    return 1;
}
static drug_vehicle_rent_player_unix[MAX_PLAYERS];
stock get_player_drug_vehicle_unix(playerid) return drug_vehicle_rent_player_unix[playerid];
stock set_player_drug_vehicle_unix(playerid, value) {
    drug_vehicle_rent_player_unix[playerid] = value;
    return 1;
}

static drugs_on_hand[MAX_PLAYERS];
stock get_player_holding_drugs(playerid) return drugs_on_hand[playerid];
stock set_player_holding_drugs(playerid, value) {
    drugs_on_hand[playerid] = value;
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

static drug_vehicle_pickupid;
stock get_drug_vehicle_pickupid() return drug_vehicle_pickupid;
stock set_drug_vehicle_pickupid(value) {
    drug_vehicle_pickupid = value;
    return 1;
}

static drugs_razgruzka_pickup;
stock get_drugs_razgruzka_pickup() return drugs_razgruzka_pickup;
stock set_drugs_razgruzka_pickup(value) {
    drugs_razgruzka_pickup = value;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

stock player_drug_vars_tonull(playerid) {
    drug_vehicle_rent_player[playerid] = INVALID_VEHICLE_ID;
    drug_vehicle_rent_player_unix[playerid] = 0;
    drugs_on_hand[playerid] = 0;
    return 1;
}
stock vehicle_drug_vars_tonull(vehicleid) {
    DrugSystemInfo[vehicleid][dsOwner] = INVALID_PLAYER_ID;
    DrugSystemInfo[vehicleid][dsCreated] = 0;
    DrugSystemInfo[vehicleid][dsLoadPickup] = 0;
    DrugSystemInfo[vehicleid][dsLoadedAmount] = 0;
    DrugSystemInfo[vehicleid][dsPosX] = 0.0;
    DrugSystemInfo[vehicleid][dsPosY] = 0.0;
    DrugSystemInfo[vehicleid][dsPosZ] = 0.0;
	DrugSystemInfo[vehicleid][dsDrugAuto] = false;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
static drugs_onwork[MAX_PLAYERS];
stock get_drugs_onwork(playerid) return drugs_onwork[playerid];
stock set_drugs_onwork(playerid, value) {
    drugs_onwork[playerid] = value;
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////
static drugs_antiflood[MAX_PLAYERS];
stock get_drugs_antiflood(playerid) return drugs_antiflood[playerid];
stock set_drugs_antiflood(playerid, value) {
    drugs_antiflood[playerid] = value;
    return 1;
}

static drugs_step[MAX_PLAYERS];
stock get_drugs_step(playerid) return drugs_step[playerid];
stock set_drugs_step(playerid, value) {
    drugs_step[playerid] = value;
    return 1;
}

static drugs_tableid[MAX_PLAYERS];
stock get_drugs_tableid(playerid) return drugs_tableid[playerid];
stock set_drugs_tableid(playerid, value) {
    drugs_tableid[playerid] = value;
    return 1;
}