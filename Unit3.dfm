object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 931
  ClientWidth = 1563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 129
    Width = 1563
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitWidth = 769
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 753
    Width = 1563
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 873
    ExplicitWidth = 58
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1563
    Height = 129
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 132
    Width = 1563
    Height = 621
    Align = alTop
    Caption = 'Panel2'
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 756
    Width = 1563
    Height = 175
    Align = alClient
    Caption = 'Panel3'
    TabOrder = 2
    ExplicitTop = 768
    ExplicitHeight = 163
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 1561
      Height = 173
      Align = alClient
      Caption = ' '
      Color = clMoneyGreen
      Constraints.MaxHeight = 120
      Constraints.MinHeight = 120
      ParentBackground = False
      TabOrder = 0
      ExplicitLeft = 0
      ExplicitTop = 736
      ExplicitWidth = 1545
      ExplicitHeight = 120
      DesignSize = (
        1561
        173)
      object RunButton: TButton
        AlignWithMargins = True
        Left = 14
        Top = 14
        Width = 153
        Height = 84
        Anchors = [akLeft, akBottom]
        BiDiMode = bdLeftToRight
        Caption = 'START'
        DoubleBuffered = False
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 0
      end
      object PauseButton: TButton
        Left = 1326
        Top = 14
        Width = 96
        Height = 84
        Anchors = [akRight, akBottom]
        BiDiMode = bdRightToLeftReadingOnly
        Caption = 'Pause'
        DoubleBuffered = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 1
      end
      object CloseButton: TButton
        Left = 1441
        Top = 14
        Width = 98
        Height = 81
        Anchors = [akRight, akBottom]
        Caption = 'Quit'
        DoubleBuffered = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 2
      end
      object ShowTrackButton: TButton
        Left = 1212
        Top = 14
        Width = 97
        Height = 81
        Anchors = [akRight, akBottom]
        Caption = 'Track'
        DoubleBuffered = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 3
      end
      object GroupBox1: TGroupBox
        Left = 173
        Top = 24
        Width = 828
        Height = 73
        Anchors = [akLeft, akBottom]
        Caption = 'Mark'
        TabOrder = 4
        DesignSize = (
          828
          73)
        object MarkerButton: TButton
          AlignWithMargins = True
          Left = 711
          Top = 16
          Width = 107
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = 'Marker'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object CommentButton: TButton
          Left = 597
          Top = 16
          Width = 108
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = 'Comment'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object IzolMarkButton: TButton
          Left = 14
          Top = 16
          Width = 118
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = #1055#1086#1074#1088'. '#1080#1079#1086#1083'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object KIPMarkButton: TButton
          Left = 138
          Top = 16
          Width = 115
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = #1050#1048#1055', '#1072#1085#1096#1083#1072#1075' '#1080' '#1087#1088'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object CrossMarkButton: TButton
          Left = 259
          Top = 16
          Width = 109
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = #1055#1077#1088#1077#1089#1077#1095#1077#1085#1080#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
        end
        object RoadMarkButton: TButton
          Left = 374
          Top = 16
          Width = 112
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = #1044#1086#1088#1086#1075#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
        end
        object TurnMarkButton: TButton
          Left = 492
          Top = 16
          Width = 99
          Height = 41
          Anchors = [akLeft, akBottom]
          Caption = #1055#1086#1074#1086#1088#1086#1090
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
        end
      end
    end
  end
end
