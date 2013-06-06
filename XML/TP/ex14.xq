xquery version "1.0";
for $x in doc("commande.xml")/boutique/commande
where $x/client="Bernard"
return $x/produit/nom