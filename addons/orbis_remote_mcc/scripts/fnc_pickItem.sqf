//======================================================MCC_fnc_pickItem===============================================================================================
//  _objet = object (the picable object)
//==============================================================================================================================================================
#define MCC_INTEL_ICON	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa"
#define MCC_INTELDOWNLOAD_ICON "\A3\ui_f\data\igui\cfg\simpleTasks\types\download_ca.paa"

private["_object", "_action", "_displayName"];

_object = _this;
if (isnil "_object" || isnull _object) exitWith {};

_object enableSimulation (_object isKindOf "man");
_displayName = getText(configFile >> "CfgVehicles" >> typeof _object >> "displayname");

if (_object getVariable ["MCC_intelItem",false]) then {
	_action = [
		_object,
		"Download Data",
		MCC_INTELDOWNLOAD_ICON,
		MCC_INTELDOWNLOAD_ICON,
		"(alive _target) && (_target distance _this < 5)",
		"(alive _target) && (_target distance _this < 5)",
		{[(_this select 0),1] spawn BIS_fnc_dataTerminalAnimate},
		{if ((_this select 4)==12) then {[(_this select 0),3] spawn BIS_fnc_dataTerminalAnimate};if ((_this select 4)==6) then {[(_this select 0),2] spawn BIS_fnc_dataTerminalAnimate}},
		compile "[(_this select 0),0] spawn BIS_fnc_dataTerminalAnimate; 0 = _this spawn MCC_fnc_pickItem_general';",
		{[(_this select 0),0] spawn BIS_fnc_dataTerminalAnimate},
		[],
		30,
		10,
		true,
		false
	] call bis_fnc_holdActionAdd;

} else {
	_action = [
		_object,
		if (_object isKindOf "man") then {format ["Interrogate %1",_displayName]} else {format ["Search %1",_displayName]},
		MCC_INTEL_ICON,
		MCC_INTEL_ICON,
		"(alive _target) && (_target distance _this < 5)",
		"(alive _target) && (_target distance _this < 5)",
		{},
		{},
		MCC_fnc_pickItem_general,
		{},
		[],
		3,
		10,
		true,
		false
	] call bis_fnc_holdActionAdd;
};

missionNamespace setVariable ["MCC_pickItem",sideLogic];
publicvariable "MCC_pickItem";
