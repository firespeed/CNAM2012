xquery version "1.0";
for $villageois in doc("villageois.xml")//villageois
for $lieu in doc("lieu.xml")//lieu
where $villageois/ID_LIEU=$lieu/ID_LIEU
return
 <NOM> {data($villageois/NOM)}</NOM>
 <LIEU> {data($lieu/NOM_LIEU)}</LIEU>
