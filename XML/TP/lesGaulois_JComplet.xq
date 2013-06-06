xquery version "1.0";
for $villageois in doc("villageois.xml")//villageois
for $lieu in doc("lieu.xml")//lieu
for $combat in doc("combat.xml")//prise_casque
for $bataille in doc("bataille.xml")//bataille
for $specialite in doc("specialite.xml")//specialite
where $villageois/ID_VILLAGEOIS=$combat/ID_VILLAGEOIS
and 	$combat/ID_BATAILLE=$bataille/ID_BATAILLE
and 	$bataille/ID_LIEU=$lieu/ID_LIEU
and 	$specialite/ID_SPECIALITE=$villageois/ID_SPECIALITE
return
<lesGaulois>
 <nom> {data($villageois/NOM)}</nom>
 <specialite> {data($specialite/NOM_SPECIALITE)}</specialite>
 <adresse> {data($villageois/ADRESSE)}</adresse>
 <image> {data($villageois/IMAGE)}</image>
 <bataille date="{data($bataille/DATE_BATAILLE)}" lieu="{data($lieu/NOM_LIEU)}"> {data($bataille/NOM_BATAILLE)} </bataille>
</lesGaulois>
