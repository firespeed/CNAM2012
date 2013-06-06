xquery version "1.0";
for $b in doc("commande.xml")//commande[1]
let $al := $b/produit
return count($al)
