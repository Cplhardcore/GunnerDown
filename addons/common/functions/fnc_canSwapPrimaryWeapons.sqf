params ["_player", "_target"];
(_target getVariable ["ACE_isUnconscious", false]) &&
side (group _target) == side (group _player);
