

<ul>
{
for $x in doc("commande.xml")//commande/client
order by $x
return <li>{$x}</li>
}
</ul>