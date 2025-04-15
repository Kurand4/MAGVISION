object PauseForm: TPauseForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1072#1091#1079#1072
  ClientHeight = 165
  ClientWidth = 740
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object ContinueButton: TButton
    Left = 40
    Top = 48
    Width = 185
    Height = 65
    Caption = #1055#1088#1086#1076#1086#1083#1078#1080#1090#1100' '#1089#1077#1089#1089#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ContinueButtonClick
  end
  object RestartButton: TButton
    Left = 280
    Top = 48
    Width = 185
    Height = 65
    Caption = #1053#1072#1095#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1089#1077#1089#1089#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = RestartButtonClick
  end
  object EndButton: TButton
    Left = 518
    Top = 48
    Width = 185
    Height = 65
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100' '#1089#1077#1089#1089#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = EndButtonClick
  end
end
