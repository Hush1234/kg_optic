// ACE_player addEventHandler ["GetInMan", {hint "getIn Fired"; private _ID = (_this select 2) addEventHandler ["Hit", {_this call orbis_fnc_tankImpactHearing}]; (_this select 2) setVariable ["eventID", _ID];}];
// ACE_player addEventHandler ["GetOutMan", {hint "getOut Fired"; private _ID = (_this select 2) getVariable ["eventID", objNull]; if !(_ID isEqualType objNull) then {(_this select 2) removeEventHandler ["Hit", _ID];};}];
