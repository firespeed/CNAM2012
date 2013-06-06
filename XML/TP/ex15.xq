xquery version "1.0";
for $x in doc("commande.xml")/boutique/commande/client
order by $x
return $x