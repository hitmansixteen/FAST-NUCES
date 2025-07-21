/****** Object:  Table [dbo].[Students]    Script Date: 02/08/2017 16:06:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Students](
	[StudentID] [int] NOT NULL,
	[StudentName] [varchar](30) NULL,
	[StudentBatch] [int] NULL,
	[CGPA] [float] NULL,
PRIMARY KEY CLUSTERED 
(
	[StudentID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (1, N'Ali', 2013, 2.625)
INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (2, N'Aysha', 2013, 4)
INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (3, N'Ahmed', 2013, 2.2)
INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (4, N'Bilal', 2012, 2.5)
INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (5, N'Zafar', 2012, 3.5)
/****** Object:  Table [dbo].[Instructors]    Script Date: 02/08/2017 16:06:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Instructors](
	[InstructorID] [int] NOT NULL,
	[InstructorsName] [varchar](30) NULL,
PRIMARY KEY CLUSTERED 
(
	[InstructorID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (1, N'Zafar')
INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (2, N'Sadia')
INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (3, N'Saima')
/****** Object:  Table [dbo].[Courses]    Script Date: 02/08/2017 16:06:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Courses](
	[CourseID] [int] NOT NULL,
	[CourseName] [varchar](30) NULL,
	[CourseCreditHours] [int] NULL,
	[InstructorID] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[CourseID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (1, N'Computer Programming', 3, 1)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (2, N'Computer Organization', 3, 2)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (3, N'Computer Programming Lab', 1, NULL)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (4, N'Database', 3, 2)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (5, N'Database  Lab', 1, 1)
/****** Object:  Table [dbo].[Registration]    Script Date: 02/08/2017 16:06:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Registration](
	[StudentID] [int] NOT NULL,
	[CourseID] [int] NOT NULL,
	[GPA] [float] NULL,
PRIMARY KEY CLUSTERED 
(
	[StudentID] ASC,
	[CourseID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 1, 3)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 3, 3)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 4, 2)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 5, 3)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 1, 2.5)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 2, 0)
INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 4, 3)
/****** Object:  ForeignKey [FK__Courses__Instruc__08EA5793]    Script Date: 02/08/2017 16:06:49 ******/
ALTER TABLE [dbo].[Courses]  WITH CHECK ADD FOREIGN KEY([InstructorID])
REFERENCES [dbo].[Instructors] ([InstructorID])
GO
/****** Object:  ForeignKey [FK__Registrat__Cours__0EA330E9]    Script Date: 02/08/2017 16:06:49 ******/
ALTER TABLE [dbo].[Registration]  WITH CHECK ADD FOREIGN KEY([CourseID])
REFERENCES [dbo].[Courses] ([CourseID])
GO
/****** Object:  ForeignKey [FK__Registrat__Stude__0DAF0CB0]    Script Date: 02/08/2017 16:06:49 ******/
ALTER TABLE [dbo].[Registration]  WITH CHECK ADD FOREIGN KEY([StudentID])
REFERENCES [dbo].[Students] ([StudentID])
GO


------------------

create view [3GPAStudents] as
	select s.StudentName
	from Students s join Registration r on s.StudentID = r.StudentID
	where r.GPA = 3

----------------------

create view StudentCGPA as
	select s.StudentName,s.StudentID, SUM(c.CourseCreditHours*r.GPA)/SUM(c.CourseCreditHours) as [CGPA]
	from Students s join Registration r on r.StudentID = s.StudentID
		join Courses c on c.CourseID = r.CourseID
	group by s.StudentName,s.StudentID

------------------------

select * from StudentCGPA

---------------------------

select COUNT(*) from StudentCGPA
where CGPA>2

-------------------------

alter view [3GPAStudents] as
	select s.StudentName,c.CourseName
	from Students s join Registration r on s.StudentID = r.StudentID
		join Courses c on c.CourseID = r.CourseID
	where r.GPA = 3

------------------------------

select * from [3GPAStudents]

-----------------------

create view Students2013Batch as
	select *
	from Students
	where StudentBatch=2013
	go

	insert into Students2013Batch
	values (12,'xyz',2014,3)
	go

	select * from Students
	select * from Students2013Batch
	go

-----------------------

create view Students2014Batch as
	select * 
	from Students
	where StudentBatch=2014
	with check option
	go

	insert into Students2014Batch
	values (13,'ABC',2014,3)
	go

	select * from Students
	select * from Students2014Batch
	go

----------------------------

insert into Students2014Batch
values (15,'ABC',2013,3)
go

----------------------------------

declare @name varchar(10);

declare @firstname varchar(10), @lastname varchar(10);

set @name = 'Ali Ahmad';

select @firstname = 'Ali',@lastname='Ahmad';

select @name = StudentName from Students where StudentBatch = 2014

select @name,@firstname,@lastname

select @lastname+', '+@firstname as fullname

---------------------------------

create procedure studentbatch2013 as
	begin
		select * from Students where StudentBatch=2013
	end
go

--------------------------------

execute studentbatch2013

---------------------------

create procedure studentofbatch @batch int as
	begin
		select * from Students where StudentBatch = @batch
	end
go

----------------------------

declare @batchNo int= 2014
execute studentofbatch @batch = @batchNo

--------------------------

create procedure gethighestcgpa @highestcgpa float output as
	begin
		select top 1 @highestcgpa = CGPA
		from Students
		order by CGPA desc
	end
	go

--------------------------

declare @cgpa float
execute gethighestcgpa 
@highestcgpa = @cgpa output

select @cgpa

---------------------------

create procedure getteacherbyname
	@name varchar, @flag int output as
	begin
		if exists(select * from Instructors where InstructorsName=@name)
		begin
			set @flag=1
			select * from Instructors where InstructorsName=@name
		end
		else
		begin
			set @flag=0
		end
	end
	go

declare @outflag float

execute getteacherbyname
@name='ALI',
@flag=@outflag output

select @outflag
go


create procedure getstudents
@letter varchar(30) as
	begin
		if lower(@letter) like '[a-z]'
		begin
			select * from Students where StudentName like @letter+'%'
		end
		else
		begin
			print 'Invalid letter, only a-z allowed'
		end
	end
	go

execute getstudents @letter='B'

execute getstudents @letter='1'


