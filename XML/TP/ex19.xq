xquery version "1.0";
for $x in doc("commande.xml")/boutique/commande
return if ($x/@type="papeterie")
then $x/client
else()