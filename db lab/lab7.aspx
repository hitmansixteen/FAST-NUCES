<%@ Page Title="" Language="vb" AutoEventWireup="false" MasterPageFile="~/Site.Master" CodeBehind="WebForm1.aspx.vb" Inherits="lab7.WebForm1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div ID="instagram" >
        <asp:Image ID="Image2"  ImageUrl="https://www.mediaweek.com.au/wp-content/uploads/2022/10/Instagram-logo.jpg"  runat="server" />

    </div>
    <br />
    <div>
        First Name:
        <asp:TextBox ID="firstName" runat="server"></asp:TextBox>
        Last Name:
        <asp:TextBox ID="lastName" runat="server"></asp:TextBox>
    </div>
    <br />
    <div>
        User Name:
        <asp:TextBox ID="userName" runat="server"></asp:TextBox>
    </div>
    <br />
    <div>
        Password:
        <asp:TextBox ID="Password" runat="server"></asp:TextBox>
    </div>
    <br />
    <div>
        Date of Birth:
        <br />
        <input type="date" id="myDate" name="myDate">  
    </div>
    <div>
        <br />
        Country: 
   <asp:DropDownList ID="d" runat="server">
   <asp:ListItem Text="Select" Value=""></asp:ListItem>
   <asp:ListItem Text="Pakistan" Value=""></asp:ListItem>
   <asp:ListItem Text="China" Value=""></asp:ListItem>
   <asp:ListItem Text="Germany" Value=""></asp:ListItem>
   <asp:ListItem Text="U.S.A" Value=""></asp:ListItem>
   </asp:DropDownList>

    </div>
      <br />
    Gender:
     <asp:CheckBox ID="CheckBox1" runat="server" Text="Male" />  
     <asp:CheckBox ID="CheckBox2" runat="server" Text="Female" /> 
    <br />
     <asp:CheckBox ID="CheckBox3" runat="server" Text="Enable Privacy" />
    <br />
    <asp:Button Text="Create Account" runat="server" />
</asp:Content>
