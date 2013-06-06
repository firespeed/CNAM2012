<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
    <xsl:apply-templates select="personnes"/>
  </html>
</xsl:template>

<xsl:template match="personnes">
  <table>
    <xsl:apply-templates select="personne"/>
  </table>
</xsl:template>

<xsl:template match="personne">
  <tr>
  <td><xsl:value-of select="nom"/></td>
  <td><xsl:value-of select="@naissance"/></td>
  <td><xsl:value-of select="@mort"/></td>
  </tr>
</xsl:template>

</xsl:stylesheet>
