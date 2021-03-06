class CfgVehicles {
	class EventHandlers;
	class LandVehicle;
	class StaticWeapon: LandVehicle {
		class Turrets;
		class MainTurret;
	};
	class StaticCannon: StaticWeapon {};

	class RHS_M119_base: StaticCannon {
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ACE_Mk6_RscWeaponRangeArtillery";
				gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
				magazines[] = {
					"RHS_mag_m1_he_12",
					"rhs_mag_m314_ilum_4",
					"orbis_mag_m60_green_4"
				};
			};
		};
	};

	class RHS_M252_Base: StaticCannon {
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ACE_Mk6_RscWeaponRangeArtillery";
				gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			};
		};
	};

	class rhs_D30_base: StaticCannon {
		ace_cargo_size = 3;
		ace_dragging_canDrag = 0;
		ace_dragging_canCarry = 0;
		
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ACE_Mk6_RscWeaponRangeArtillery";
				gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
				magazines[] = {
					"rhs_mag_3of56",
					"rhs_mag_bk13",
					"rhs_mag_d462",
					"rhs_mag_s463"
				};
			};
		};
		
		class EventHandlers: EventHandlers {
		init = "{(_this select 0) removeMagazine _x} forEach ['rhs_mag_3of56','rhs_mag_bk13','rhs_mag_d462','rhs_mag_s463'];";
			class RHS_EventHandlers {
				fired = "_this spawn rhs_fnc_fired_d30";
			};
		};
        class ACE_Actions {
            class ACE_MainActions {
				condition = "true";
				displayName = "Interactions";
				distance = 5;
				selection = "gunnerview";
				
				class ace_interaction_flip {
					condition = "call ace_interaction_fnc_canFlip";
					displayName = "Flip";
					statement = "[""ace_interaction_flip"",_target,_target] call CBA_fnc_targetEvent";
				};
				
				class ACE_Passengers {
					condition = "alive _target";
					displayName = "Passengers";
					exceptions[] = {"isNotSwimming"};
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
					statement = "";
				};
				
				class ace_rearm_Rearm {
					condition = "_this call ace_rearm_fnc_canRearm";
					displayName = "Rearm";
					distance = 9;
					exceptions[] = {"isNotInside"};
					icon = "\z\ace\addons\rearm\ui\icon_rearm_interact.paa";
					statement = "_this call ace_rearm_fnc_rearm";
				};
				
				class ace_reload_CheckAmmo {
					condition = "[_player,_target] call ace_reload_fnc_canCheckAmmo";
					displayName = "Check Ammo";
					distance = 2;
					exceptions[] = {"isNotInside","isNotSwimming","isNotSitting"};
					statement = "[_player,_target] call ace_reload_fnc_checkAmmo";
				};
				
				class ACE_Load {
					condition = "alive _target";
					displayName = "Disassemble D-30";
					distance = 5;
					exceptions[] = {"isNotInside"};
					statement = "[_player,_target] spawn deadly_artilleryup_fnc_load";
					showDisabled = 0;
				};
            };
        };
		
		class UserActions {
			class fold {
				condition = "false";
				displayName = "Fold gun";
				onlyForplayer = 0;
				position = "aimpoint";
				radius = 2.51;
				statement = "[this,1] call rhs_fnc_d30_pack;";
			};
			class Unfold {
				condition = "false";
				displayName = "Unfold gun";
				onlyForplayer = 0;
				position = "aimpoint";
				radius = 2.51;
				statement = "[this,0] call rhs_fnc_d30_pack;";
			};
		};
	};

	class MBT_01_base_F;
	class MBT_01_arty_base_F : MBT_01_base_F {
		class Turrets;
		class MainTurret;	
	};
	
	class rhsusf_m109tank_base : MBT_01_arty_base_F {
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ACE_Mk6_RscWeaponRangeArtillery";
				gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			};
		};
	};
	
	class ace_rearm_defaultCarriedObject;
	class dummy_artillery_shell : ace_rearm_defaultCarriedObject {
		model = "\rhsusf\addons\rhsusf_m252\rhs_81case_single_small";
	};
	class dummy_artillery_shell2 : ace_rearm_defaultCarriedObject {
		model = "\a3\Props_F_Orange\Items\Tools\Crowbar_01_F.p3d";
	};

	/* class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
				class ace_mk6mortar_rangetalbe {
					statement = "['ACE_RangeTable_82mm'] call ace_mk6mortar_fnc_rangeTableOpen";
				};
				class M119_Rangetable_Open: ace_mk6mortar_rangetalbe {
					displayName = "Open M119 105mm Rangetable";
					condition = "'M119_RangeTable' in (items ACE_player)";
					statement = "['M119_RangeTable'] call ace_mk6mortar_fnc_rangeTableOpen";
				};
			};
		};
	}; */
	
	class ThingX;
	
    class Deadly_D30_Container: ThingX {
		author = "Deadly";
		displayname = "Disassembled D-30";
		editorCategory = "EdCat_Supplies";
		editorSubcategory = "EdSubcat_Storage";
		armor = 800;
		faction = "BLU_F";
		icon = "iconObject_1x3";
		scope = 2;
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		slingLoadCargoMemoryPointsDir[] = {};
		
		
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Repair_F.jpg";
		model = "\A3\Supplies_F_Heli\Slingload\Slingload_01_Repair_F.p3d";
		
		ace_cargo_size = -1;
		ace_dragging_canDrag = 1;
		ace_dragging_DragDirection = 90;
		ace_dragging_DragPosition[] = {0,2.4,0.1};
		ace_dragging_canCarry = 0;
		
		class EventHandlers: EventHandlers {
			init = "(_this select 0) setMass 2000;";
		};
		
        class ACE_Actions {
            class ACE_MainActions {
				condition = "alive _target";
				displayName = "Interactions";
				distance = 6;
				selection = "";
				
				class ACE_Unload {
					condition = "true";
					displayName = "Assemble D-30";
					distance = 6;
					statement = "[_player,_target] spawn deadly_artilleryup_fnc_unload";
					showDisabled = 0;
				};
            };
        };
    };
};
