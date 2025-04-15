object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 793
  ClientWidth = 1514
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
    Top = 76
    Width = 1514
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 73
    ExplicitWidth = 720
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 684
    Width = 1514
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 665
    ExplicitWidth = 128
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1514
    Height = 76
    Align = alTop
    Caption = 'Panel1'
    Color = clMoneyGreen
    ParentBackground = False
    TabOrder = 0
    DesignSize = (
      1514
      76)
    object CheckBox_UseGPS: TCheckBox
      Left = 23
      Top = 21
      Width = 121
      Height = 17
      Caption = 'Do not use GPS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object GroupBox4: TGroupBox
      Left = 312
      Top = 8
      Width = 217
      Height = 49
      Caption = 'Info'
      TabOrder = 1
      DesignSize = (
        217
        49)
      object L_StartLat: TLabel
        Left = 142
        Top = 14
        Width = 63
        Height = 13
        Anchors = [akBottom]
        Caption = '_________'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitLeft = 129
        ExplicitTop = 22
      end
      object L_StartLng: TLabel
        Left = 142
        Top = 33
        Width = 63
        Height = 13
        Anchors = [akBottom]
        Caption = '_________'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitLeft = 129
        ExplicitTop = 41
      end
      object LabelGPS: TLabel
        Left = 12
        Top = 12
        Width = 24
        Height = 13
        Anchors = [akBottom]
        Caption = 'Port:'
        ExplicitLeft = 10
        ExplicitTop = 20
      end
      object GPSLabel: TLabel
        Left = 60
        Top = 12
        Width = 36
        Height = 13
        Anchors = [akBottom]
        Caption = '______'
        ExplicitLeft = 54
        ExplicitTop = 20
      end
      object L_SatNum: TLabel
        Left = 60
        Top = 31
        Width = 36
        Height = 13
        Anchors = [akBottom]
        Caption = '______'
        ExplicitLeft = 54
        ExplicitTop = 39
      end
      object Label7: TLabel
        Left = 12
        Top = 31
        Width = 30
        Height = 13
        Anchors = [akBottom]
        Caption = 'SatN :'
        ExplicitLeft = 10
        ExplicitTop = 39
      end
    end
    object GroupBox5: TGroupBox
      Left = 566
      Top = 8
      Width = 179
      Height = 49
      Caption = 'Distance (m)'
      TabOrder = 2
      object Label3: TLabel
        Left = 22
        Top = 24
        Width = 53
        Height = 13
        Caption = 'From start '
      end
      object Label4: TLabel
        Left = 10
        Top = 58
        Width = 24
        Height = 13
        Caption = 'Total'
        Visible = False
      end
      object Edit_Way: TEdit
        Left = 97
        Top = 22
        Width = 73
        Height = 24
        Alignment = taRightJustify
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        Text = '0'
      end
      object Edit_Way1: TEdit
        Left = 112
        Top = 58
        Width = 73
        Height = 24
        Alignment = taRightJustify
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        Text = '0'
        Visible = False
      end
    end
    object GroupBox7: TGroupBox
      Left = 798
      Top = 8
      Width = 201
      Height = 49
      Caption = 'MaxShift (m)'
      TabOrder = 3
      DesignSize = (
        201
        49)
      object Label_dLng: TLabel
        Left = 135
        Top = 33
        Width = 49
        Height = 13
        Anchors = [akBottom]
        Caption = '_______'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitTop = 20
      end
      object Label_dLat: TLabel
        Left = 57
        Top = 33
        Width = 49
        Height = 13
        Anchors = [akBottom]
        Caption = '_______'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitTop = 20
      end
      object Label8: TLabel
        Left = 24
        Top = 33
        Width = 13
        Height = 13
        Anchors = [akBottom]
        Caption = 'Lt:'
        ExplicitTop = 20
      end
      object Label12: TLabel
        Left = 114
        Top = 33
        Width = 15
        Height = 13
        Anchors = [akBottom]
        Caption = 'Lg:'
        ExplicitTop = 20
      end
    end
    object GroupBox6: TGroupBox
      Left = 1005
      Top = 21
      Width = 201
      Height = 32
      Caption = 'Samples'
      TabOrder = 4
      DesignSize = (
        201
        32)
      object L_CoordCount: TLabel
        Left = 65
        Top = 15
        Width = 49
        Height = 13
        Anchors = [akBottom]
        Caption = '_______'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object L_BadCoordCount: TLabel
        Left = 135
        Top = 15
        Width = 49
        Height = 13
        Anchors = [akBottom]
        Caption = '_______'
        Color = clRed
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
    end
    object Panel3: TPanel
      Left = 1228
      Top = 9
      Width = 278
      Height = 43
      Anchors = [akLeft, akBottom]
      BorderStyle = bsSingle
      Caption = ' '
      TabOrder = 5
      object Label1: TLabel
        Left = 101
        Top = 22
        Width = 11
        Height = 13
        Caption = 'U:'
        Color = clRed
        ParentColor = False
      end
      object Label2: TLabel
        Left = 189
        Top = 23
        Width = 11
        Height = 13
        Caption = 'D:'
        Color = clBlue
        ParentColor = False
      end
      object StaticText_Plot1: TLabel
        Left = 118
        Top = 18
        Width = 40
        Height = 18
        Alignment = taRightJustify
        Caption = '_____'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object StaticText_Plot2: TLabel
        Left = 204
        Top = 18
        Width = 40
        Height = 18
        Alignment = taRightJustify
        Caption = '_____'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object StaticText_PlotN: TLabel
        Left = 20
        Top = 18
        Width = 40
        Height = 18
        Alignment = taRightJustify
        Caption = '_____'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBackground
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 5
        Top = 19
        Width = 11
        Height = 13
        Caption = 'N:'
        Color = clBlue
        ParentColor = False
      end
    end
    object GPSButton: TButton
      Left = 150
      Top = 8
      Width = 144
      Height = 47
      Anchors = [akLeft, akTop, akRight, akBottom]
      BiDiMode = bdRightToLeftReadingOnly
      Caption = 'Run GPS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentFont = False
      TabOrder = 6
      ExplicitHeight = 44
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 79
    Width = 1514
    Height = 605
    Align = alTop
    Caption = 'Panel2'
    TabOrder = 1
    ExplicitTop = 76
    object Splitter3: TSplitter
      Left = 1422
      Top = 1
      Height = 603
      Align = alRight
      ExplicitLeft = 1224
      ExplicitTop = 248
      ExplicitHeight = 100
    end
    object Panel5: TPanel
      Left = 1425
      Top = 1
      Width = 88
      Height = 603
      Align = alRight
      Caption = 'Panel5'
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 0
      DesignSize = (
        88
        603)
      object GroupBox8: TGroupBox
        Left = 4
        Top = 168
        Width = 84
        Height = 233
        Anchors = [akRight]
        Caption = 'Way (m)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object ButtonWay1: TButton
          Left = 3
          Top = 23
          Width = 75
          Height = 49
          Caption = '50'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object ButtonWay2: TButton
          Left = 3
          Top = 92
          Width = 75
          Height = 50
          Caption = '100'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object ButtonWay3: TButton
          Left = 3
          Top = 161
          Width = 75
          Height = 50
          Caption = '150'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
      end
      object BitBtn1: TBitBtn
        Left = 6
        Top = 16
        Width = 75
        Height = 49
        Anchors = [akTop, akRight]
        DoubleBuffered = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000333
          3333333333777F33333333333309033333333333337F7F333333333333090333
          33333333337F7F33333333333309033333333333337F7F333333333333090333
          33333333337F7F33333333333309033333333333FF7F7FFFF333333000090000
          3333333777737777F333333099999990333333373F3333373333333309999903
          333333337F33337F33333333099999033333333373F333733333333330999033
          3333333337F337F3333333333099903333333333373F37333333333333090333
          33333333337F7F33333333333309033333333333337373333333333333303333
          333333333337F333333333333330333333333333333733333333}
        NumGlyphs = 2
        ParentDoubleBuffered = False
        TabOrder = 1
      end
      object BitBtn2: TBitBtn
        Left = 6
        Top = 544
        Width = 75
        Height = 49
        Anchors = [akRight, akBottom]
        DoubleBuffered = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333303333
          333333333337F33333333333333033333333333333373F333333333333090333
          33333333337F7F33333333333309033333333333337373F33333333330999033
          3333333337F337F33333333330999033333333333733373F3333333309999903
          333333337F33337F33333333099999033333333373333373F333333099999990
          33333337FFFF3FF7F33333300009000033333337777F77773333333333090333
          33333333337F7F33333333333309033333333333337F7F333333333333090333
          33333333337F7F33333333333309033333333333337F7F333333333333090333
          33333333337F7F33333333333300033333333333337773333333}
        NumGlyphs = 2
        ParentDoubleBuffered = False
        TabOrder = 2
      end
    end
    object Panel6: TPanel
      Left = 1
      Top = 1
      Width = 1421
      Height = 603
      Align = alClient
      Caption = 'Panel6'
      TabOrder = 1
      object VizorPlot1: TDBChart
        Left = 1
        Top = 1
        Width = 1419
        Height = 601
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Border.Visible = True
        BorderRound = 1
        MarginBottom = 0
        MarginLeft = 5
        MarginRight = 10
        MarginTop = 0
        MarginUnits = muPixels
        Title.Font.Color = clBlack
        Title.Font.Height = -8
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          'mkTl')
        Title.VertMargin = 3
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.ExactDateTime = False
        BottomAxis.Grid.DrawEvery = 2
        BottomAxis.Increment = 100.000000000000000000
        BottomAxis.LabelsSeparation = 30
        BottomAxis.Maximum = 25.000000000000000000
        DepthAxis.Automatic = False
        DepthAxis.AutomaticMaximum = False
        DepthAxis.AutomaticMinimum = False
        DepthAxis.Maximum = 0.470000000000000000
        DepthAxis.Minimum = -0.530000000000000000
        DepthTopAxis.Automatic = False
        DepthTopAxis.AutomaticMaximum = False
        DepthTopAxis.AutomaticMinimum = False
        DepthTopAxis.Maximum = 0.470000000000000000
        DepthTopAxis.Minimum = -0.530000000000000000
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.AxisValuesFormat = '#0.###'
        LeftAxis.Maximum = 855.000000000000000000
        LeftAxis.Minimum = 417.500000000000000000
        LeftAxis.PositionUnits = muPixels
        LeftAxis.TickOnLabelsOnly = False
        Legend.Visible = False
        Pages.AutoScale = True
        Pages.MaxPointsPerPage = 500
        RightAxis.Automatic = False
        RightAxis.AutomaticMaximum = False
        RightAxis.AutomaticMinimum = False
        RightAxis.Grid.Visible = False
        RightAxis.Minimum = -5.000000000000000000
        RightAxis.Title.Caption = #1043#1083#1091#1073#1080#1085#1072
        View3D = False
        Align = alClient
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Color = clWhite
        TabOrder = 0
        PrintMargins = (
          15
          43
          15
          43)
        ColorPaletteIndex = 13
        object Series1: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Frame.Width = 3
          Marks.Visible = False
          PercentFormat = '##0.##,%'
          LinePen.Color = clRed
          LinePen.Width = 2
          TreatNulls = tnDontPaint
          XValues.Name = 'X'
          XValues.Order = loAscending
          XValues.ValueSource = 'ID_IZM'
          YValues.Name = 'Y'
          YValues.Order = loNone
          YValues.ValueSource = 'C2_X_R'
        end
        object Series2: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clBlue
          LinePen.Color = clBlue
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series3: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 4227072
          LinePen.Color = 4227072
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series7: TPointSeries
          Marks.Arrow.Color = 4194368
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Color = 4194368
          Marks.Callout.Arrow.Visible = True
          Marks.Callout.Length = 8
          Marks.Font.Height = -7
          Marks.Shadow.Color = 8487297
          Marks.Style = smsPointIndex
          Marks.Visible = True
          ShowInLegend = False
          ValueFormat = '0.#'
          ClickableLine = False
          Pointer.InflateMargins = True
          Pointer.Style = psDiamond
          Pointer.Visible = True
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series4: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16711808
          ShowInLegend = False
          LinePen.Color = 16711808
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 687
    Width = 1514
    Height = 106
    Align = alClient
    Caption = 'Panel4'
    Color = clMoneyGreen
    ParentBackground = False
    TabOrder = 2
    ExplicitTop = 684
    ExplicitHeight = 109
    DesignSize = (
      1514
      106)
    object RunButton: TButton
      AlignWithMargins = True
      Left = 23
      Top = 24
      Width = 170
      Height = 70
      Anchors = [akLeft, akTop, akRight, akBottom]
      BiDiMode = bdLeftToRight
      Caption = 'START'
      DoubleBuffered = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 0
      ExplicitHeight = 73
    end
    object PauseButton: TButton
      Left = 1236
      Top = 16
      Width = 119
      Height = 78
      Anchors = [akTop, akRight, akBottom]
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
      ExplicitHeight = 81
    end
    object CloseButton: TButton
      Left = 1376
      Top = 13
      Width = 119
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
      ExplicitTop = 16
    end
    object Button1: TButton
      Left = 1087
      Top = 16
      Width = 119
      Height = 81
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
      Left = 232
      Top = 16
      Width = 577
      Height = 81
      Caption = 'Mark'
      TabOrder = 4
      DesignSize = (
        577
        81)
      object MarkerButton: TButton
        AlignWithMargins = True
        Left = 37
        Top = 16
        Width = 144
        Height = 49
        Anchors = [akLeft, akTop, akRight, akBottom]
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
        Left = 222
        Top = 16
        Width = 144
        Height = 49
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = 'Comment'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
      object Button2: TButton
        Left = 408
        Top = 16
        Width = 145
        Height = 49
        Caption = #1050#1048#1055', '#1072#1085#1096#1083#1072#1075' '#1080' '#1087#1088'.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
    end
  end
end
