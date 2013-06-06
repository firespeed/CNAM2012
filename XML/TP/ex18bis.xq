xquery version "1.0";

for $x in distinct-values(doc("commande.xml")/boutique/commande/upper-case(client))
return $x