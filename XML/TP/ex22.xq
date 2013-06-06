xquery version "1.0";
<html>
<body>

<table border="2" align="center" cellspacing="1" bordercolor="blue">
<caption>
    <h2>Liste des clients    </h2>
</caption>

<tr>
{
for $x in doc("commande.xml")//commande/client
order by $x
return <td>{$x}</td>
}
</tr>
</table>
</body>
</html>
