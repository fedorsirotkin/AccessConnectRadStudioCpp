object MainForm: TMainForm
  Left = 0
  Top = 0
  ActiveControl = DBGrid1
  Caption = #1057#1077#1090#1100' '#1082#1080#1085#1086#1090#1077#1072#1090#1088#1086#1074
  ClientHeight = 442
  ClientWidth = 894
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object DBGridCinemas: TDBGrid
    Left = 8
    Top = 90
    Width = 878
    Height = 79
    Align = alCustom
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1053#1086#1084#1077#1088
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 171
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        Width = 171
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1042#1084#1077#1089#1090#1080#1084#1086#1089#1090#1100
        Width = 171
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1050#1080#1085#1086#1090#1077#1072#1090#1088
        Width = 171
        Visible = True
      end>
  end
  object DBEdit1: TDBEdit
    Left = 81
    Top = 8
    Width = 131
    Height = 21
    TabOrder = 1
  end
  object FirstBTN: TBitBtn
    Left = 81
    Top = 35
    Width = 131
    Height = 33
    Caption = #1053#1072#1078#1084#1080' '#1084#1077#1085#1103
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 2
    OnClick = FirstBTNClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 248
    Width = 878
    Height = 183
    DataSource = DataSource2
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1053#1086#1084#1077#1088
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 139
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1040#1076#1088#1077#1089
        Width = 139
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1058#1077#1083#1077#1092#1086#1085
        Width = 139
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1057#1072#1081#1090
        Width = 139
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1042#1084#1077#1089#1090#1080#1084#1086#1089#1090#1100
        Width = 139
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 168
    Width = 240
    Height = 25
    DataSource = DataSource2
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 168
    Top = 221
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Edit1'
  end
  object GroupBox1: TGroupBox
    Left = 432
    Top = 208
    Width = 337
    Height = 34
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086': '
    TabOrder = 6
    object RadioButton1: TRadioButton
      Left = 56
      Top = 17
      Width = 113
      Height = 17
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 168
      Top = 16
      Width = 113
      Height = 17
      Caption = #1040#1076#1088#1077#1089
      TabOrder = 1
    end
  end
  object ADOConnectionFilmLibrary: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=Cinem' +
      'aNetwork'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 392
    Top = 32
  end
  object ADOTable2: TADOTable
    Connection = ADOConnectionFilmLibrary
    CursorType = ctStatic
    TableName = #1050#1080#1085#1086#1090#1077#1072#1090#1088#1099
    Left = 512
    Top = 56
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 608
    Top = 56
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnectionFilmLibrary
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'Adress'
        DataType = ftString
        Size = 2
        Value = '""'
      end>
    SQL.Strings = (
      'SELECT * FROM '#1050#1080#1085#1086#1090#1077#1072#1090#1088#1099
      'where '#1040#1076#1088#1077#1089' = :Adress')
    Left = 704
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 8
    object ItemMenu1: TMenuItem
      Caption = #1055#1091#1085#1082#1090' '#1084#1077#1085#1102' 1'
      object N111: TMenuItem
        Caption = #1055#1086#1076#1087#1091#1085#1082#1090' 1 '#1084#1077#1085#1102' 1'
      end
      object N211: TMenuItem
        Caption = #1055#1086#1076#1087#1091#1085#1082#1090' 2 '#1084#1077#1085#1102' 1'
      end
    end
    object ItemMenu2: TMenuItem
      Caption = #1055#1091#1085#1082#1090' '#1084#1077#1085#1102' 2'
      OnClick = ItemMenu2Click
    end
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnectionFilmLibrary
    Parameters = <>
    Left = 704
    Top = 56
  end
  object ADOTable1: TADOTable
    Connection = ADOConnectionFilmLibrary
    CursorType = ctStatic
    IndexFieldNames = #1050#1080#1085#1086#1090#1077#1072#1090#1088
    MasterFields = #1053#1086#1084#1077#1088
    MasterSource = DataSource2
    TableName = #1047#1072#1083#1099
    Left = 512
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 608
    Top = 8
  end
end
