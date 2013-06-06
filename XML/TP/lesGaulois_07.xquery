xquery version "1.0";
for $x in /lesgaulois/villageois
	where $x/NOM_CASQUE="Centurion"
return $x/NOM 
