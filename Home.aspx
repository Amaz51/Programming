<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="Home.aspx.cs" Inherits="practice2.Home" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div id ="msg" runat="server">
    </div>
    <asp:GridView ID ="ItemGrid" runat ="server" OnRowDeleting="ItemGrid_RowDeleting" OnSelectedIndexChanged="ItemGrid_SelectedIndexChanged" AutoGenerateColumns="False" EnableViewState="False" OnRowCancelingEdit="ItemGrid_RowCancelingEdit" OnRowEditing="ItemGrid_RowEditing" OnRowUpdating="ItemGrid_RowUpdating">
        <Columns>

            <asp:CommandField ShowEditButton="True" />
            <asp:CommandField ShowDeleteButton="True" />

            <asp:TemplateField HeaderText="ItemNo" HeaderStyle-HorizontalAlign="Left">
<EditItemTemplate>
<asp:Label ID="txtItemNo" runat="server" Text='<%#
Bind("ItemNo") %>'></asp:Label>
</EditItemTemplate>
<ItemTemplate>
<asp:Label ID="lblItemNo" runat="server" Text='<%#
Bind("ItemNo") %>'></asp:Label>
</ItemTemplate>
<HeaderStyle HorizontalAlign="Left"></HeaderStyle>
</asp:TemplateField>
<asp:TemplateField HeaderText="ItemName" HeaderStyle-HorizontalAlign="Left">
<EditItemTemplate>
<asp:TextBox ID="txtItemName" runat="server" Text='<%#
Bind("ItemName") %>'></asp:TextBox>
</EditItemTemplate>
<ItemTemplate>
<asp:Label ID="lblItemName" runat="server" Text='<%#
Bind("ItemName") %>'></asp:Label>
</ItemTemplate>
<HeaderStyle HorizontalAlign="Left"></HeaderStyle>
</asp:TemplateField>
            <asp:TemplateField HeaderText="TotalUnits" HeaderStyle-HorizontalAlign="Left">
<EditItemTemplate>
<asp:TextBox ID="txtTotalUnits" runat="server" Text='<%#
Bind("TotalUnits") %>'></asp:TextBox>
</EditItemTemplate>
<ItemTemplate>
<asp:Label ID="lblTotalUnits" runat="server" Text='<%#
Bind("TotalUnits") %>'></asp:Label>
</ItemTemplate>
<HeaderStyle HorizontalAlign="Left"></HeaderStyle>
</asp:TemplateField>
        </Columns>
    </asp:GridView>
    <br> Item Number:
      <asp:TextBox ID="TxtItmNo" runat="server" Width="247px" Height="17px"></asp:TextBox>
    <br> Item Name:
     <asp:TextBox ID="TxtItmName" runat="server" Width="247px" Height="17px"></asp:TextBox>
    <br> Total Units:
     <asp:TextBox ID="TxtUnits" runat="server" Width="247px" Height="17px"></asp:TextBox>
    <br><br />
    <asp:Button ID="Button1" runat="server" Text="Add New Item" Width="119px" OnClick="New_Item_Click"/>
    <br/><br/>
    <div id="message" runat="server">
    </div>
    <br/>
</asp:Content>
