xquery version "1.0";
for $x in 	//lesgaulois/villageois
	where $x/NOM_BATAILLE="Babaorum"
return $x/NOM
