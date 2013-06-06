xquery version "1.0";
for $b in doc("commande.xml")//commande[1]/produit
let $al := $b/nom
return $al 
