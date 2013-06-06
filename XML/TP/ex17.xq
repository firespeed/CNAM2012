xquery version "1.0";
for $b in doc("commande.xml")//commande[1]
let $al := $b/produit
return <produit nombre="{count($al)}">
{ $al }
</produit>