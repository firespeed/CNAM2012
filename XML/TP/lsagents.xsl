<?xml version="1.0" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" encoding="ISO-8859-1" />

<xsl:template match="/">
<html>
<head>
<title>
Liste des personnes
</title>
</head>
<body>
<h1>
Liste des personnes
</h1>
<blockquote>
    <xsl:apply-templates select="//personne/nom" />
</blockquote>
</body>
</html>
</xsl:template>

<xsl:template match="personne/nom">
     <p>
     <xsl:value-of select="." />
     </p>
</xsl:template>

</xsl:stylesheet>
