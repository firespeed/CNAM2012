xquery version "1.0";
for $x in doc("LesGauloisBataille.xml")//UnGaulois
return 
if ($x/UneBataille="Babaorum")
then let $a :=$x/@Nom 
else() 