object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1086#1083#1086#1074#1086#1082' '#1092#1086#1088#1084#1099' 2'
  ClientHeight = 547
  ClientWidth = 757
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 128
    Top = 104
    Width = 569
    Height = 120
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBChart1: TDBChart
    Left = 152
    Top = 230
    Width = 400
    Height = 250
    Title.Text.Strings = (
      #1044#1080#1072#1075#1088#1072#1084#1084#1072)
    TabOrder = 1
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      DataSource = ADOTable1
      XLabelsSource = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = #1053#1086#1084#1077#1088
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = #1053#1086#1084#1077#1088
    end
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = MainForm.ADOConnectionFilmLibrary
    CursorType = ctStatic
    Filtered = True
    TableName = #1057#1090#1088#1072#1085#1099' '#1087#1088#1086#1080#1079#1074#1086#1076#1089#1090#1074#1072
    Left = 64
    Top = 48
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 152
    Top = 56
  end
end
