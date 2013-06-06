xquery version "1.0";
let $r:=doc("commande.xml") //commande
return
<nombre> {count($r)} </nombre>
