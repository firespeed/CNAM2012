xquery version "1.0";
for $villageois in doc("villageois.xml")//villageois
for $lieu in doc("lieu.xml")//lieu
for $combat in doc("combat.xml")//prise_casque
for $bataille in doc("bataille.xml")//bataille
where $villageois/ID_VILLAGEOIS=$combat/ID_VILLAGEOIS
and 	$combat/ID_BATAILLE=$bataille/ID_BATAILLE
and 	$bataille/ID_LIEU=$lieu/ID_LIEU
return
<resultat>
 <NOM> {data($villageois/NOM)}</NOM>
 <BATAILLE> {data($bataille/NOM_BATAILLE)} </BATAILLE>
 <LIEU> {data($lieu/NOM_LIEU)} </LIEU>
</resultat>
